// DISPLAY THE PROCESS ID (PID) OF PARENT AND CHILD
// PROCESSES USING GETPID() AND GETPPID()
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main()
{
    int id;
    printf("Process ID of Parent & Child\n");
    // calling fork()
    id = fork();
    if (id == 0)
    {
        printf("Child Process is calling ...\n");
        printf("Process ID (PID) of Child Process : %d\n", getpid());
    }
    else
    {
        printf("Parent Process is calling ...\n");
        printf("Process ID (PID) of Parent Process : %d\n", getppid());
    }
    return 0;
}