// Write a C program create unnamed pipe to generate parent process and will read from it.

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

    int fd[2];
    pid_t pid;

    char write_msg[] = "Hello from child process";
    char read_msg[100];

    if (pipe(fd) == -1)
    {
        perror("PIPE");
        return 1;
    }

    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    // child process
    if (pid == 0)
    {
        close(fd[0]); // close read end, child will write;
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
    }
    else
    {
        // parent process
        close(fd[1]); // close write end, parent will read;
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Parent recieved : %s\n", read_msg);
        close(fd[0]);
    }

    return 0;
}