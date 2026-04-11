//Write a C program to create a file with hole in it.

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{

    int fp = open("file_with_hole.txt", O_CREAT | O_WRONLY, 0644);

    char buff1[] = "Start of file";
    char buff2[] = "End of file";

    if (fp == -1)
    {
        perror("FILE");
        return 1;
    }

    write(fp, buff1, strlen(buff1));

    lseek(fp, 100, SEEK_CUR);

    write(fp, buff2, strlen(buff2));

    printf("File with hole created.\n");
    close(fp);
    return 0;
}