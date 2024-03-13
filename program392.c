#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;
    char fname[30];

    printf("Enter the file name that you want to open : \n");
    scanf("%s",fname);


    fd = open(fname, O_RDONLY);

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