#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;

    fd = open("Demo.txt", O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file");
        return -1;
    }
    else
    {
        printf("File is successfully opened fd %d\n",fd);
    }
    return 0;
}