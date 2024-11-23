// Criação de Processos com fork
// Escreva um programa que crie dois processos filhos usando fork. Cada processo filho deve imprimir seu PID e o PID do processo pai.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int pid1, pid2;
   


    pid1 = fork();

    if(pid1 == -1)
    {
        printf("Erro no fork 1");
        return (1);
    }
    
    if(pid1 == 0) {
        printf("Filho 1: Meu PID = %d | PID do meu pai = %d\n", getpid(), getppid());
        return (0);
    }

    pid2 = fork();

    if(pid2 == -1)
    {
        printf("Erro no fork 1");
        return (1);
    }

    if(pid2 == 0) {
        printf("Filho 2: Meu PID = %d | PID do meu pai = %d\n", getpid(), getppid());
        return (0);
    }

    printf("Pai: Meu PID = %d\n", getpid());

    wait(NULL);
    wait(NULL);

    return (0);
}