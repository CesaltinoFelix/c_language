// Exercise: Inter-process Communication with Pipes
// Write a program that creates a pipe between a parent process and a child process.
// The parent should send a string to the child, which should convert it to uppercase and send it back to the parent.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

void lower_to_upper(char *str) {
    while (*str != '\0') {
        if (islower(*str))
            (*str) = toupper(*str);
        str++;
    }
}

int main(void) {
    int pipe_to_child[2], pipe_to_parent[2];
    pid_t pid;
    char str[100];

    if (pipe(pipe_to_child) == -1 || pipe(pipe_to_parent) == -1) {
        perror("Error creating pipes!");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("Error creating fork!");
        return 2;
    }

    if (pid == 0) {
        close(pipe_to_child[1]);
        close(pipe_to_parent[0]);

        int i = 0;
        while (read(pipe_to_child[0], &str[i], 1) > 0) {
            i++;
        }
        str[i] = '\0';

        lower_to_upper(str);

        write(pipe_to_parent[1], str, strlen(str));
        close(pipe_to_child[0]);
        close(pipe_to_parent[1]);
        exit(0);
    } else {
        close(pipe_to_child[0]);
        close(pipe_to_parent[1]);

        char *text = "Hello, my name is Cesaltino Felix!";
        write(pipe_to_child[1], text, strlen(text));
        close(pipe_to_child[1]);

        wait(NULL);

        int bytes_read = read(pipe_to_parent[0], str, sizeof(str) - 1);
        str[bytes_read] = '\0';

        close(pipe_to_parent[0]);

        printf("Converted Text: %s\n", str);
    }

    return 0;
}
