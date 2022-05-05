#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    int p[2];
    printf("\tSending and receving static message\n");
    char *m1 = "hello1", *m2 = "mit2";
    char buf[1024];
    int r = pipe(p);
    if (r<0){
        printf("Failed to create unnamed pipe\n");
        exit(1);
    }
    write(p[1], m1, strlen(m1));
    write(p[1], m2, strlen(m1));
    printf("Two messages sent successfullly (Process 1)\n");
    printf("Message from unnamed pipe (Process 2)\n");
    read(p[0], buf, sizeof(buf));
    printf("%s\n", buf);
    return 99;
}