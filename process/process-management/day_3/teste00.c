#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    //pipefd[0] - read
    //pipefd[1] - write
    int idade;

    if(pipe(pipefd) == -1)
    {
        perror("Error creating pipe");
        exit(1);
    }

    int pid = fork();
    if (pid == 0)
    {   
        close(pipefd[0]);
        printf("Digite a sua idade: ");
        scanf("%d", &idade);
        write(pipefd[1], &idade, sizeof(int));
        close(pipefd[1]);
    } else {
        close(pipefd[1]);
        read(pipefd[0], &idade, sizeof(int));
        printf("Idade: %d\n", idade);
        close(pipefd[0]);
        wait(NULL);
    }
    return (0);
}