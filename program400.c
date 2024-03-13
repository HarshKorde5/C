#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int fd = 0;
    char fname[30];
    int iRet = 0,iSize = 0;
    char *Arr = NULL;

    printf("Enter the file name that you want to open : \n");
    scanf("%s",fname);

    printf("Enter the number of bytes that you want to read : \n");
    scanf("%d",&iSize);

    Arr = (char *)malloc(iSize);

    fd = open(fname, O_RDWR);

    if(fd == -1)
    {
        printf("Unable to create the file");
        return -1;
    }

    iRet = read(fd,Arr,iSize);

    printf("%d bytes gets successfully fetched from the file \n",iRet);

    printf("Data from the file is : \n");
    write(1,Arr,iRet);
    printf("\n");
    close(fd);
    free(Arr);
    
    return 0;
}