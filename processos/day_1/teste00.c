#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    
    int id_pai = getpid();
    int id;
    
    id = fork();
    if(id == 0)
    {
        printf("Esse e o processo filho e tem o pid = %d\n", getpid());
        printf("O pid do processo pai e = %d\n", getppid());
    }else if(id > 0)
    {
        printf("Esse e o processo pai, pid do filho = %d!!!\n", id);
        printf("Processo pai pid = %d\n\n", id_pai);
        wait(NULL);

    }
    return (0);
}