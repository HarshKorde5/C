// Write a C program that print the exit status of a terminated child process.
#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{

    pid_t pid = fork();

    int status = 0;

    if (pid == -1)
    {
        perror("FORK");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child process running\n");
        sleep(2);
        int exit_status = rand() % 100;

        printf("Exiting child with exit status : %d\n", exit_status);
        exit(exit_status);
    }
    else
    {
        printf("Parent process waiting for child to exit.\n");
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            printf("Child process exited normally with exit status : %d\n",WEXITSTATUS(status));
        }
        else
        {
            printf("Child process exited abnormally with exit status : %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}