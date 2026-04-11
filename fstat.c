
// Write a C program to find file properties such as inode number, number of hard link, File
// permissions, File size, File access and modification time and so on of a given file using fstat() system call.

#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    int fp = open(argv[1], O_RDONLY);

    if (fp == -1)
    {
        perror("FILE");
        return 1;
    }

    struct stat filestat;

    if (fstat(fp, &filestat) == -1)
    {
        perror("fstat");
        close(fp);
        return 1;
    }

    printf("\nFile properties : %s", argv[1]);
    printf("\nInode number : %ld", filestat.st_ino);
    printf("\nHard links : %ld", filestat.st_nlink);

    printf("\nLast access time : %s", ctime(&filestat.st_atime));
    printf("\nLast modified time : %s", ctime(&filestat.st_mtime));

    printf("\nFile permissions : ");
    printf((S_ISDIR(filestat.st_mode)) ? "d" : "-");
    printf((filestat.st_mode & S_IRUSR) ? "r" : "-");
    printf((filestat.st_mode & S_IWUSR) ? "w" : "-");
    printf((filestat.st_mode & S_IXUSR) ? "x" : "-");
    printf((filestat.st_mode & S_IRGRP) ? "r" : "-");
    printf((filestat.st_mode & S_IWGRP) ? "w" : "-");
    printf((filestat.st_mode & S_IXGRP) ? "x" : "-");
    printf((filestat.st_mode & S_IROTH) ? "r" : "-");
    printf((filestat.st_mode & S_IWOTH) ? "w" : "-");
    printf((filestat.st_mode & S_IXOTH) ? "x" : "-");

    printf("\n");
    close(fp);

    return 0;
}