// Write a C program to find whether a given file is present in current directory or not? 

/*
path
The path to the file or directory that you want to access.
amode
The access mode you want to check. This must be either:
F_OK : test for file existence.
or a bitwise ORing of the following access permissions to be checked, as defined in the header <unistd.h>:

R_OK : test for read permission.
W_OK : test for write permission.
X_OK : for a directory, test for search permission. Otherwise, test for execute permission.


Description:
The access() function checks to see if the file or directory specified by path exists and if it can be accessed with the file access permissions given by amode. However, unlike other functions (open() for example), it uses the real user ID and real group ID in place of the effective user and group IDs.

Returns:
0
The file or directory exists and can be accessed with the specified mode.
-1
An error occurred (errno is set).

*/

#include<stdio.h>
#include<unistd.h>

int main(){

    char filename[20];

    printf("Enter file name : ");
    scanf("%s", filename);

    if(access(filename, F_OK) == 0){

        printf("\nFile %s exists\n",filename);
    }else{
        printf("\nFile %s doesn't exist\n",filename);
    }


    return 0;
}