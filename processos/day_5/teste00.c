// Substituição de Processos com `exec`
    
// Escreva um programa que crie um processo filho usando `fork`. O filho deve substituir seu código pelo programa `/bin/ls` usando `execlp`.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    int pid;

    pid = fork();
    if(pid == -1) {
        perror("Falha ao criar o fork");
        return (1);
    }

    if(pid == 0) {
        printf("Filho PID = %d: substituindo pelo programa '/bin/ls'...\n", getpid());
        execlp("/bin/ls", "ls", "-l", (char *)NULL);
        // Caso execlp falhe:
        perror("Erro ao executar execlp");
        return (2);
    }else {
        int status;
        int terminated_pid;

        while((terminated_pid = wait(&status)) > 0)
        {
             if (WIFEXITED(status)) {
                printf("Pai: o processo filho com PID = %d terminou com status = %d\n", 
                       terminated_pid, WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Pai: o processo filho com PID = %d foi encerrado pelo sinal = %d\n", 
                       terminated_pid, WTERMSIG(status));
            }
        }
    }
    return (0);
}