#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(void) {

    int id1 = fork();
    int id2 = fork();

    if(id1 == 0)
    {
        if(id2 == 0)
        {
            printf("Y Esse e o processo filho do filho ID = %d\n", getpid());
            printf("X Esse e o processo pai do filho do filho ID = %d\n\n", getppid());
        }else{
            printf("X Esse e o processo filho do pai ID = %d\n", getpid());
            printf("PAI Esse e o processo pai filho ID = %d\n\n", getppid());
            wait(NULL);
        }
    }else {
        if(id2 == 0) {
            printf("Z Esse e o processo filho do pai ID = %d\n", getpid());
            printf("PAI Esse e o processo pai ID = %d\n\n", getppid());
        }
        else {
            printf("PAI Esse e o processo pai ID = %d\n\n", getpid());
        }
    }
    while( wait(NULL) != -1 || errno != ECHILD)
        printf("Waited for a child to end");
    return (0);
}