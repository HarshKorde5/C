// Write a C program to display the last access and modified time of a given file.
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>

int main()
{

    char filename[20];
    struct stat filestat;

    printf("Enter file name : ");
    scanf("%s", filename);

    if(stat(filename, &filestat) == -1){
        perror("stat");
        return 1;
    }

    printf("Last accessed time : %s\n", ctime(&filestat.st_atime));
    printf("Last modified time : %s\n",ctime(&filestat.st_mtime));

    return 0;
}