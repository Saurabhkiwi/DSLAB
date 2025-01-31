#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

// Function to perform Bubble Sort
void bubbleSort(char *arr[], int n) {
    char *temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(char *arr[], int n) {
    char *temp;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        // Swap
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    char *strings[MAX_STRINGS];

    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); // Consume newline character

    // Read strings from user
    for (int i = 0; i < n; i++) {
        strings[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
        printf("Enter string %d: ", i + 1);
        fgets(strings[i], MAX_LENGTH, stdin);
        strings[i][strcspn(strings[i], "\n")] = 0; // Remove newline character
    }

    // Create two child processes
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid1 == 0) {
        // Child 1: Bubble Sort
        bubbleSort(strings, n);
        printf("Child 1 (Bubble Sort) sorted strings:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", strings[i]);
        }
        exit(0);
    }

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid2 == 0) {
        // Child 2: Selection Sort
        selectionSort(strings, n);
        printf("Child 2 (Selection Sort) sorted strings:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", strings[i]);
        }
        exit(0);
    }

    // Parent process: wait for one of the child processes to terminate
    int status;
    pid_t terminated_pid = wait(&status);
    if (terminated_pid == pid1) {
        printf("Child 1 terminated first.\n");
    } else {
        printf("Child 2 terminated first.\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }

    return 0;
}
