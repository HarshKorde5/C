// Write a C program that will only list all subdirectories in alphabetical order from currentdirectory.

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

int is_directory(const struct dirent* entry){
    struct stat filestat;

    if(stat(entry->d_name, &filestat) == 0){
        if(S_ISDIR(filestat.st_mode)){
            return 1;
        }
    }

    return 0;
}

int main()
{

    struct dirent** namelist;

    int n = scandir(".", &namelist, is_directory, alphasort);

    if(n < 0){
        perror("SCANDIR");
    }else{
        for(int i = 0; i < n;i++){
            printf("%s\n", namelist[i]->d_name);
            free(namelist[i]);
        }
    }

    free(namelist);

    return 0;
}