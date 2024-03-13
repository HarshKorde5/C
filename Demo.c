#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
    printf("%d\n",O_RDONLY);
    printf("%d\n",O_WRONLY);
    printf("%d\n",O_RDWR);

    
    return 0;
}