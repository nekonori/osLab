// PRINT THE RETURNED VALUE OF CHILD AND PARENT PROCESSES USING FORK
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
    pid_t id;
    printf("Return value of parent and child\n");
    id = fork();
    if(id==0){
        printf("Child is calling...\n");
        printf("Return value of child: %d\n", id);
    } else {
        printf("Parent process is calling...\n");
        printf("Return value of parent: %d\n", id);
    }
    return 0;
}