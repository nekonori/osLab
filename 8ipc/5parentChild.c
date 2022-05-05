#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int p[2];
    printf("IPC-Parent and Child using Pipe (One Way)\n");
    char* message = (char*) malloc(sizeof(char*));
    char buf[1024];
    int r = pipe(p);
    if(r<0){
        printf("Failed to create unnamed pipe\n");
        exit(1);
    }
    int f = fork();
    if(f<0){
        printf("Error in creating child process\n");
        exit(1);
    } else if (f == 0){
        printf("Child process\n");
        printf("Enter a message: ");
        fgets(message, 50, stdin);
        write(p[1], message, 50);
    } else {
        wait(NULL);
        printf("Parent process\n");
        read(p[0], buf, 50);
        printf("Received message: \n%s", buf);
    }
    return 0;
}