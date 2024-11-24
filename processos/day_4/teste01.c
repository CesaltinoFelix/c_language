// Sincronização de Processos
// Crie um programa onde o processo pai espera todos os processos filhos terminarem antes de imprimir "Todos os filhos terminaram". Use wait ou waitpid.

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


int main(void) {

    int pid1, pid2;

    pid1 = fork();
    if(pid1 == -1) {
        perror("Erro ao criar o fork 1\n");
        return (1);
    }

    if(pid1 == 0)
    {
        sleep(4);
        printf("Filho 1: PID = %d TERMINOU!\n", getpid());
        return (0);
    }

    pid2 = fork();
    if(pid2 == -1) {
        perror("Erro ao criar o fork 2\n");
        return (2);
    }

    if(pid2 == 0)
    {
        sleep(2);
        printf("Filho 2: PID = %d TERMINOU!\n", getpid());
        return (0);
    }

    int status;
    int terminated_pid;
    while((terminated_pid = wait(&status)) > 0) {
        if(WIFEXITED(status))
            printf("Filho com PID = %d terminou com status de saída: %d\n", terminated_pid, WEXITSTATUS(status));

    }

    printf("Todos os filhos terminaram\n");
    return (0);
}