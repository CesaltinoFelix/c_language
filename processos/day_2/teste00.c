#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(void) {
    int id1 = fork();
    int id2 = fork();

    if (id1 == 0) {
        if (id2 == 0) {
            printf("[Processo Y] Sou o filho do primeiro filho.\n");
            printf("    PID: %d | PPID (pai): %d\n\n", getpid(), getppid());
        } else {
            printf("[Processo X] Sou o primeiro filho direto do pai.\n");
            printf("    PID: %d | PPID (pai): %d\n\n", getpid(), getppid());
            wait(NULL);
        }
    } else {
        if (id2 == 0) {
            printf("[Processo Z] Sou o segundo filho direto do pai.\n");
            printf("    PID: %d | PPID (pai): %d\n\n", getpid(), getppid());
        } else {
            printf("[Processo PAI] Sou o processo pai original.\n");
            printf("    PID: %d\n\n", getpid());
        }
    }

    while (wait(NULL) != -1 || errno != ECHILD) {
        printf("[Processo %d] Esperando um processo filho terminar...\n", getpid());
    }

    return 0;
}
