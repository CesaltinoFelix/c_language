// Processos em Cadeia
// Implemente um programa que crie três processos em cadeia (pai → filho → neto). Cada processo deve exibir uma mensagem diferente e seu PID.
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void) {

    int pid1, pid2;


    pid1 = fork();
    if(pid1 == -1)
    {
        perror("Falha ao criar o fork 1!");
        return(1);
    }

    if(pid1 == 0) {

        pid2 = fork();
        if(pid2 == -1)
        {
            perror("Falha ao criar o fork 2!");
            return(2);
        }
        if(pid2 == 0)
        {
            printf("Sou o processo neto. Meu PID é [%d]. Meu pai é o processo filho com PID [%d].\n\n", getpid(), getppid());
        } else {
            printf("Sou o processo filho. Meu PID é [%d]. Meu pai tem o PID [%d].\n", getpid(), getppid());
            printf("Filho: Criei um processo neto com PID [%d].\n\n", pid2);
            wait(NULL);
        }
    } else {
            printf("Sou o processo pai. Meu PID é [%d].\n", getpid());
            printf("Pai: Criei um processo filho com PID [%d].\n\n", pid1);
            wait(NULL);
    }
    return (0);
}