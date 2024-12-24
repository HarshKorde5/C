/*
display each substring from a string using c

*/

#include<stdio.h>
#include<string.h>



//////////////////////////////////////////////////////////////////////////////
//  Brute Force : O(n^3)
//////////////////////////////////////////////////////////////////////////////
void displaySubstrings(char str[])
{
    int n = strlen(str);

    printf("All substrings of the given string \"%s\":\n",str);

    for(int i = 0;i < n;i++)
    {
        for(int j = i;j < n;j++)
        {
            for(int k = i;k <= j;k++)
            {
                printf("%c",str[k]);
            }

            printf("\n");
        }
    }
}


///////////////////////////////////////////////////////////////////////////////
//  Precompute substrings using dynamic programming
///////////////////////////////////////////////////////////////////////////////
void precomputeSubstrings(char *str,char substrings[][100],int *count)
{
    int n = strlen(str);

    *count = 0;

    for(int i = 0;i < n;i++)
    {
        for(int j = i;j < n;j++)
        {
            strncpy(substrings[*count],&str[i],j-i+1);
            substrings[*count][j-i+1] = '\0';
            (*count)++;
        }
    }
}

int main()
{
    char str[100];
    char substrings[1000][100];
    int count = 0;
    
    printf("Enter a string : ");
    scanf("%[^\n]s",str);

    // displaySubstrings(str);
    precomputeSubstrings(str,substrings,&count);

    printf("All substrings of the given string\"%s\" : \n",str);

    for(int i = 0;i < count;i++)
    {
        printf("%s\n",substrings[i]);
    }

    return 0;
}