
// Write a C program that catches the ctrl-c (SIGINT) signal for the first time and display the
// appropriate message and exits on pressing ctrl-c again.

#include <stdio.h>
#include <signal.h>

void singal_handler(int sig){

    printf("You have pressed Ctrl+C...Press again to exit the program.\n");
    signal(SIGINT,SIG_DFL);
}
int main()
{

    signal(SIGINT, singal_handler);

    printf("Program is running...Press Ctrl + c\n");

    while(1){}

    return 0;
}