#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, arrival, burst, priority, waiting, turnaround, remaining;
} Process;

// Function to swap processes
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort processes by arrival time
void sortByArrival(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival)
                swap(&p[j], &p[j + 1]);
        }
    }
}

// **Preemptive SJF Scheduling**
void preemptiveSJF(Process p[], int n) {
    int completed = 0, time = 0, minIdx;
    float avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++)
        p[i].remaining = p[i].burst;

    printf("\nGantt Chart: ");
    while (completed < n) {
        minIdx = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0) {
                if (minIdx == -1 || p[i].remaining < p[minIdx].remaining)
                    minIdx = i;
            }
        }

        if (minIdx == -1) {
            time++;
            continue;
        }

        printf("| P%d ", p[minIdx].pid);
        p[minIdx].remaining--;
        time++;

        if (p[minIdx].remaining == 0) {
            completed++;
            p[minIdx].turnaround = time - p[minIdx].arrival;
            p[minIdx].waiting = p[minIdx].turnaround - p[minIdx].burst;
            avgWT += p[minIdx].waiting;
            avgTAT += p[minIdx].turnaround;
        }
    }
    printf("|\n");

    printf("\nAvg Waiting Time: %.2f\n", avgWT / n);
    printf("Avg Turnaround Time: %.2f\n", avgTAT / n);
}

// **Round Robin Scheduling**
void roundRobin(Process p[], int n, int quantum) {
    int time = 0, remaining = n;
    float avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++)
        p[i].remaining = p[i].burst;

    printf("\nGantt Chart: ");
    while (remaining > 0) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0) {
                printf("| P%d ", p[i].pid);
                if (p[i].remaining > quantum) {
                    time += quantum;
                    p[i].remaining -= quantum;
                } else {
                    time += p[i].remaining;
                    p[i].turnaround = time - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    avgWT += p[i].waiting;
                    avgTAT += p[i].turnaround;
                    p[i].remaining = 0;
                    remaining--;
                }
            }
        }
    }
    printf("|\n");

    printf("\nAvg Waiting Time: %.2f\n", avgWT / n);
    printf("Avg Turnaround Time: %.2f\n", avgTAT / n);
}

// **Non-Preemptive Priority Scheduling**
void priorityScheduling(Process p[], int n) {
    int completed = 0, time = 0, highestIdx;
    float avgWT = 0, avgTAT = 0;

    printf("\nGantt Chart: ");
    while (completed < n) {
        highestIdx = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].burst > 0) {
                if (highestIdx == -1 || p[i].priority < p[highestIdx].priority)
                    highestIdx = i;
            }
        }

        if (highestIdx == -1) {
            time++;
            continue;
        }

        printf("| P%d ", p[highestIdx].pid);
        time += p[highestIdx].burst;
        p[highestIdx].turnaround = time - p[highestIdx].arrival;
        p[highestIdx].waiting = p[highestIdx].turnaround - p[highestIdx].burst;
        p[highestIdx].burst = 0;
        completed++;
        avgWT += p[highestIdx].waiting;
        avgTAT += p[highestIdx].turnaround;
    }
    printf("|\n");

    printf("\nAvg Waiting Time: %.2f\n", avgWT / n);
    printf("Avg Turnaround Time: %.2f\n", avgTAT / n);
}

int main() {
    int n, choice, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process *p = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time, Priority for Process %d: ", i + 1);
        scanf("%d %d %d", &p[i].arrival, &p[i].burst, &p[i].priority);
        p[i].pid = i + 1;
    }

    do {
        printf("\nMENU:\n1. Preemptive SJF\n2. Round Robin\n3. Non-Preemptive Priority Scheduling\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sortByArrival(p, n);
                preemptiveSJF(p, n);
                break;
            case 2:
                printf("Enter Time Quantum: ");
                scanf("%d", &quantum);
                roundRobin(p, n, quantum);
                break;
            case 3:
                sortByArrival(p, n);
                priorityScheduling(p, n);
                break;
            case 4:
                printf("Exiting...\n");
                free(p);
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    free(p);
    return 0;
}
