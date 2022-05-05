#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *findprime(int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
        if (n % (i + 1) == 0)
            c++;
    if (c == 2)
        return "The Given Number is a prime\n";
    else
        return "The Given Number is NOT a prime\n";
}

int main()
{
    int p[2];
    printf("Finding prime number pipe\n");
    char buf[1024];
    int r = pipe(p);
    if (r < 0)
    {
        printf("Failed to create unnamed pipe\n");
        exit(1);
    }
    int ele;
    printf("Enter a num: ");
    scanf("%d", &ele);
    char *msg = (char *)malloc(sizeof(char *));
    sprintf(msg, "%d", ele);
    write(p[1], msg, sizeof(msg));
    printf("One message sent successfully (Process 1)\n");
    printf("Message from unnamed pipe (Process 2)\n");
    read(p[0], buf, sizeof(msg));
    printf("Received data: %s\n", buf);
    int num = atoi(buf);
    char *rs = findprime(num);
    printf("%s\n", rs);
    return 0;
}