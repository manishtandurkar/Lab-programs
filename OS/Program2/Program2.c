#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main(int argc, char* argv[]) {
    printf("Main function: \n");
    int retval = 1;
    pid_t pid = fork();
    if(pid < 0)
        printf("Error in fork operation.\n");
    if(pid == 0) {
        printf("PID for child process: %d\nPID of its parent process: %d\n", getpid(), getppid());
        execl("./binsearch", argv[1], NULL);
    } else {
        printf("PID for parent process: %d\n", getpid());
        wait(&retval);
        if(WIFEXITED(retval) == 1)
            printf("Child terminated normally\n");
        else {
            printf("Child terminated abnormally\n");
            exit(0);
        }
    }
}