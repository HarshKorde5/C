// Write a C program to display all the files from current directory which are created in a particular month.

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, char **argv)
{

    DIR *d;
    struct stat filestat;
    struct dirent *entry;

    d = opendir(".");

    if (!d)
    {
        perror("DIR");
        return 1;
    }

    int month = atoi(argv[1]);

    printf("\nFiles modified in month %d:\n", month);

    while (entry = readdir(d))
    {
        if (stat(entry->d_name, &filestat) == -1)
        {
            perror("STAT");
            return 1;
        }

        struct tm *timeinfo = localtime(&filestat.st_mtime);

        if ((timeinfo->tm_mon + 1) == month)
        {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(d);
    return 0;
}