
// Write a C program to move the content of file1.txt to file2.txt and remove the file1.txt from directory.

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024

int main()
{
    int source, dest;

    source = open("a.txt", O_RDONLY);
    if(source == -1){
        perror("SOURCE");
        return 1;
    }
    dest = open("b.txt", O_CREAT | O_RDWR, 0644);
    if(dest == -1){
        perror("DESTINATION");
        return 1;
    }

    char buff[1024];
    int readBytes;

    while((readBytes = read(source,&buff,MAX)) > 0){
        write(dest,buff,readBytes);
    }

    close(source);
    close(dest);

    if(unlink("a.txt") == 0){
        printf("Content copied from a.txt to b.txt and removed a.txt\n");
    }else{
        printf("Unable to remove a.txt\n");
    }

    return 0;
}
