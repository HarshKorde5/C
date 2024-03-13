/*
Create new file

int creat(char *File_name,int Permission)

File_name : Name of file that you want to create
Permission : Permission for file


*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;
    char fname[30];

    printf("Enter the file name that you want to create : \n");
    scanf("%s",fname);


    fd = creat(fname, 0777);

    if(fd == -1)
    {
        printf("Unable to create the file");
        return -1;
    }
    else
    {
        printf("File is successfully created \n");
    }
    
    return 0;
}