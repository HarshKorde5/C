/*
Write the data into the file

int write(char FD,char *Data,int Size);

FD : File descriptor returned by open
Data : Name of array / string which contains the data that you want to write
Size : Number of bytes you want to write

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;
    char fname[30];
    int iRet = 0;

    char Arr[] = "abcdefghijklmnopqrstuvwxyz";

    printf("Enter the file name that you want to create : \n");
    scanf("%s",fname);


    fd = open(fname, O_RDWR);

    if(fd == -1)
    {
        printf("Unable to create the file");
        return -1;
    }

    iRet = write(fd,Arr,10);

    printf("%d bytes gets successfully written in the file \n",iRet);
    close(fd);
    
    return 0;
}