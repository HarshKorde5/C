/*
Write a C program that behaves like a shell (command interpreter). It has its own prompt say
“NewShell$”. Any normal shell command is executed from your shell by starting a child process
to execute the system program corresponding to the command. It should additionally
interpret the following command.
i) list f - print name of all files in directory
ii) list n - print number of all entries
iii) list i - print name and inode of all files  - 3

i) typeline +10 <filename> - print first 10 lines of file
ii) typeline -20 <filename> - print last 20 lines of file
iii) typeline a <filename> - print all lines of file - 3


i) search f <pattern><filename> - search first occurrence of pattern in filename
ii) search c <pattern><filename> - count no. of occurrences of pattern in filename
iii) search a <pattern><filename> - search all occurrences of pattern in filename - 3

i) count c - print number of characters in file
ii) count w - print number of words in file
iii) count l - print number of lines in file - 4
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX 1024

void list(char option, char *dirname)
{

    DIR *d;

    struct dirent *dir;
    struct stat inode;

    int count = 0;

    d = opendir(dirname);
    if (!d)
    {
        perror("opendir");
        return;
    }

    while ((dir = readdir(d)) != NULL)
    {

        if (option == 'f')
        {
            printf("%s\n", dir->d_name);
        }
        else if (option == 'n')
        {
            count++;
        }
        else if (option == 'i')
        {
            stat(dir->d_name, &inode);
            printf("%s\t%ld\n", dir->d_name, inode.st_ino);
        }
    }

    if (option == 'n')
    {
        printf("Total entries : %d\n", count);
    }

    closedir(d);
}

void typeline(char *opt, char *filename)
{
    int fp = open(filename, O_RDONLY);

    if (fp == -1)
    {
        perror("File");
        return;
    }

    if (opt[0] == 'a')
    {
        char ch;
        while (read(fp, &ch, 1) != 0)
        {
            printf("%c", ch);
        }

        close(fp);
        return;
    }

    int n = atoi(opt);
    int line = 0;
    char ch;

    if (n > 0)
    {

        while (read(fp, &ch, 1) != 0)
        {
            if (ch == '\n')
            {
                line++;
            }

            if (line == n)
            {
                break;
            }

            printf("%c", ch);
        }

        printf("\n");
        close(fp);
        return;
    }

    if (n < 0)
    {
        while (read(fp, &ch, 1) != 0)
        {
            if (ch == '\n')
            {
                line++;
            }
        }

        lseek(fp, 0, SEEK_SET);
        int x = 0;

        while (read(fp, &ch, 1) != 0)
        {
            if (ch == '\n')
            {
                x++;
            }

            if (x == (line + n))
            {
                break;
            }
        }

        while (read(fp, &ch, 1) != 0)
        {
            printf("%c", ch);
        }

        printf("\n");
        close(fp);
        return;
    }
}

void search(char option, char *pattern, char *filename)
{

    int fp = open(filename, O_RDONLY);

    if (fp == -1)
    {
        perror("File");
        return;
    }

    char buffer[80];
    int count = 0;

    while (read(fp, &buffer, 80) != 0)
    {
        char *pos = buffer;

        while((pos = strstr(pos, pattern))!=  NULL){
            count++;

            if(option == 'f'){
                printf("Found at line : %s\n", buffer);
                close(fp);
                return;
            }

            if(option == 'a'){
                printf("Found : %s\n",buffer);
            }

            pos += strlen(pattern);
        }
        
    }

    if(option == 'c'){
        printf("Total occurrence : %d\n", count);
    }
    close(fp);
    return;
}

void count(char option, char* filename)
{
    int fp = open(filename, O_RDONLY);
    if(!fp){
        perror("FILE");
        return;
    }
    int characters = 0, words = 0, lines = 0;
    char ch;

    while(read(fp, &ch, 1) != 0){

        characters++;

        if(ch == ' '){
            words++;
        }
        if(ch == '\n'){
            lines++;
            words++;
        }
    }
    lines++;
    words++;


    switch(option){
        case 'c':
            printf("\nTotal number of characters in file are : %d\n", characters);
        break;

        case 'w':
            printf("\nTotal number of words in file are : %d\n", words);
        break;

        case 'l':
            printf("\nTotal number of lines in file are : %d\n", lines);
        break;
    }

    close(fp);
    return;
}

int main()
{

    char input[MAX];
    system("clear");

    char *args[5];

    while (1)
    {
        printf("myShell$ ");
        fflush(stdin);
        fgets(input, MAX, stdin);

        input[strcspn(input, "\n")] = 0;

        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL)
        {
            i++;
            args[i] = strtok(NULL, " ");
        }

        if (strcmp(args[0], "exit") == 0)
        {
            printf("Bye!\n");
            break;
        }

        if (strcmp(args[0], "list") == 0)
        {
            list(args[1][0], args[2]);
        }
        else if (strcmp(args[0], "typeline") == 0)
        {
            typeline(args[1], args[2]);
        }
        else if (strcmp(args[0], "search") == 0)
        {
            search(args[1][0], args[2], args[3]);
        }
        else if (strcmp(args[0], "count") == 0)
        {
            count(args[1][0], args[2]);
        }
        else
        {

            pid_t pid = fork();

            if (pid == 0)
            {
                execvp(args[0], args);
                perror("Command failed");
                exit(1);
            }
            else
            {
                wait(NULL);
            }
        }
    }

    return 0;
}