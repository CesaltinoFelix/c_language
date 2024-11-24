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

        execlp("/bin/ls", "ls", "-l", (char *)NULL);

    }else {
        int status;
        int terminated_pid;

        while((terminated_pid = wait(&status)) > 0)
        {
            if(WIFEXITED(status))
                printf("O processo filho com PID = %d terminou com estatus %d\n", terminated_pid, WEXITSTATUS(status));
        }
    }
    return (0);
}