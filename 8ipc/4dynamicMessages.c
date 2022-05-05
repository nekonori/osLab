#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r, nl;
    static int c = 0;
    char *msg = (char *)malloc(sizeof(char *));
    char bf[1024];
    int p[2];
    printf("\tSending & Receiving Dynamic Messages using Pipe\n");
    // create unnamed pipe using pipe system call
    r = pipe(p);
    if (r < 0)
    {
        printf("Failed to created unnamed pipe...\n");
        exit(1);
    }
    printf("Enter the number of messages to send: ");
    scanf("%d", &nl);
    printf("Enter the messages:\n");
    for (int i = 0; i < nl; i++)
    {
        printf("Message #%d: \n", (i + 1));
        scanf("%s", msg);
        write(p[1], msg, 50);
        printf("\tOne SMS is sent\n");
        printf("\tSMS Length: %d\n", (int)strlen(msg));
        c++;
    }
    printf("%d Messages are Sent Successfully\n", c);
    printf("Message from Unnamed Pipe:\n");
    printf("Process 2:\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < nl; i++)
    {
        read(p[0], bf, 50);
        printf("%s\n", bf);
    }
    return 0;
}