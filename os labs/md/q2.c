#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string1> <string2> ... <stringN>\n", argv[0]);
        return 1;
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process: sort and display the strings
        char *temp;
        for (int i = 1; i < argc - 1; i++) {
            for (int j = i + 1; j < argc; j++) {
                if (strcmp(argv[i], argv[j]) > 0) {
                    // Swap the strings
                    temp = argv[i];
                    argv[i] = argv[j];
                    argv[j] = temp;
                }
            }
        }

        printf("Sorted Strings:\n");
        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
        exit(0); // Exit child process
    } else {
        // Parent process: wait for the child to finish
        wait(NULL);

        // Display unsorted strings
        printf("Unsorted Strings:\n");
        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }

    return 0;
}/* #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int agrc , char *argv[]){
	pid_t pid = fork();
	int count = argc - 1;
	if(pid < 0){
		printf("error");
		return 1;
	}
	else if(pid == 0){
		char *temp;
		for(int i = 1 ; i< count ; i++){
			for(int j = i+1 ; j < argc ; j++){
				if(strcmp(argv[i] , argv[j]) > 0){
					temp = argv[i];
					argv[i] = argv[j];
					argv[j] = temp;
				}
			}
		}
		printf("Sorted Strings: \n");
		for(int i = 1 ; i< argc ; i++){
			printf("%s\n" , argv[i]);
		}
		exit(0);
	}
	else{
		wait(NULL);
		printf("Unsorted Strings: \n");
                for(int i = 1 ; i< argc ; i++){
                        printf("%s\n" , argv[i]);
                }
	}
	return 0 ; 
}*/

