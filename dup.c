
// Write a C program that redirects standard output to a file output.txt. (use of dup and open system call).

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{

    int fd_in, fd_out;

    fd_in = open("a.txt", O_RDONLY);
    if (fd_in == -1)
    {
        perror("INPUT");
        return 1;
    }

    fd_out = open("b.txt", O_RDWR);
    if (fd_out == -1)
    {
        perror("OUPUT");
        return 1;
    }

    char buffer[1024];

    dup2(fd_in, STDIN_FILENO);
    dup2(fd_out, STDOUT_FILENO);

    int a = 0, b = 0;

    scanf("%d %d", &a, &b);

    printf("SUM : %d + %d = %d\n", a, b, a + b);

    close(fd_in);
    close(fd_out);
    
    return 0;
}