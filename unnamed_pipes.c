/*
Write a C program to create an unnamed pipe. The child process will write following three
messages to pipe and parent process display it.
Message1 = “Hello World”
Message2 = “Hello SPPU”
Message3 = “Linux is Funny”
*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd[2];
    char buff[20];

    char msg1[] = "Hello World";
    char msg2[] = "Hello SPPU";
    char msg3[] = "Linux is funny";

    if (pipe(fd) == -1)
    {
        perror("PIPE");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Fork");
        return 1;
    }

    if (pid == 0)
    {
        close(fd[0]);

        write(fd[1], msg1, sizeof(msg1));
        write(fd[1], msg2, sizeof(msg2));
        write(fd[1], msg3, sizeof(msg3));

        close(fd[1]);
    }
    else
    {
        close(fd[1]);

        read(fd[0], buff, sizeof(msg1));
        printf("First message from child : %s\n", buff);

        read(fd[0], buff, sizeof(msg2));
        printf("Second message from child : %s\n", buff);

        read(fd[0], buff, sizeof(msg3));
        printf("Third message from child : %s\n", buff);

        close(fd[0]);
    }

    return 0;
}