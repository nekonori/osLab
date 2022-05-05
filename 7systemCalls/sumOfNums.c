// SUM OF NUMBERS IN ARRAY USING CHILD AND PARENT PROCESS
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    int i, a[] = {12, 21, 12};
    int s = 0;
    printf("Sum of Numbers in Child and Execution of Parent after the child\n");
    int p = fork();
    if (p < 0)
    {
        printf("Failed to create a new Process ...\n");
        exit(0);
    }
    else if (p == 0)
    {
        printf("Child Process is calling...\n");
        for (i = 0; i < 3; i++)
        {
            s = s + a[i];
        }
        printf("The result is: %d\n", s);
        printf("Child Process is completed...\n");
    }
    else
    {
        wait(NULL);
        printf("Parent Process is calling after the Child Process ...\n");
    }
    return 0;
}