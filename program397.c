#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int fd = 0;
    char fname[30];
    int iRet = 0;

    char Arr[50] = {'\0'};

    printf("Enter the file name that you want to open : \n");
    scanf("%s",fname);

    fd = open(fname, O_RDWR);

    if(fd == -1)
    {
        printf("Unable to create the file");
        return -1;
    }

    iRet = read(fd,Arr,5);

    printf("%d bytes gets successfully fetched from the file \n",iRet);

    printf("Data from the file is : %s\n",Arr);

    close(fd);
    
    return 0;
}