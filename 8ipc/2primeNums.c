#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// function returns string as a result
char *findprime(int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
        if (n % (i + 1) == 0)
            c++;
    if (c == 2)
        return "The Given Number is a prime...\n";
    return "The Given Number is NOT a prime...\n";
}
// main function
int main()
{
    int r, ele;
    // pipe descriptors
    int p[2];
    printf("\tFinding Prime Number-Pipe\n");    
    char buf[1024];
    // create unnamed pipe using pipe system call
    r = pipe(p);
    if (r < 0)
    {
        printf("Failed to created unnamed pipe...\n");
        exit(1);
    }
    char *msg = "18";
    write(p[1], msg, sizeof(msg));
    printf("One Message is sent successfully...(Process 1)\n");
    printf("Message from Unnamed Pipe: (Process 2)\n");
    read(p[0], buf, sizeof(buf));
    printf("Received Data: %s\n", buf);
    int num = atoi(buf);
    char *rs = findprime(num);
    printf("%s\n", rs);
    return 0;
}