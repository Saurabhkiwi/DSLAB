#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	pid_t pid = fork(); //created a child process
	if(pid < 0){
		//fork failed
		exit(1);
	}
	else if(pid == 0){
		//this block is executed by the child process
		printf("Child Process:\n");
		printf("PID : %d\n" , getpid());
		printf("PPID : %d\n" , getppid());
		printf("Hello from child process\n");
 	}
	else{
	//this block is executed by parent process 
		printf("Parent process: \n");
		printf("PID : %d\n" , getpid());
                printf("PPID : %d\n" , getppid());
                printf("Hello from parent process\n");
		
 	}
	return 0;
}

	
