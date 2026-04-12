// Write a C program to display as well as resets the environment variable such as path, home, root etc.

#include <stdio.h>
#include <stdlib.h>

void display_and_reset(const char* var, const char* new){
    char *curr = getenv(var);

    if(curr != NULL){
        printf("Current %s is %s.\n",var,curr);        
    }else{
        printf("%s environment variable not set.\n",var);
    }

    if(setenv(var,new,1) == 0){

        char* updated = getenv(var);
        printf("%s reset successfully to %s.\n",var,updated);
    }else{
        printf("Failed to reset %s.\n",var);
    }
}

int main()
{
    const char* new_path = "/home/newpath";
    const char* new_home = "/home/newpath/newhome";
    const char* new_root = "/new/root/newroot";

    display_and_reset("PATH", new_path);
    display_and_reset("HOME", new_home);
    display_and_reset("ROOT", new_root);


    return 0;
}