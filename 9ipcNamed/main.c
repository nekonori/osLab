#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

char m1[] = "Hello world", m2[] = "Good morning", m3[] = "welcome home";

void sendMessage(){
	int fd = open("sms.txt", O_CREAT|O_WRONLY,0777);
	write(fd,m1,strlen(m1));
	write(fd,m2,strlen(m2));
	write(fd,m3,strlen(m3));
	printf("Three messages sent\n");
	close(fd);
}

void receiveMessage(){
	int fp = open("sms.txt", O_RDONLY);
	char buf1[100], buf2[100], buf3[100];
	read(fp,buf1,strlen(m1));
	read(fp,buf2,strlen(m2));
	read(fp,buf3,strlen(m3));
	printf("Message from FIFO:\n");
	printf("%s\n", buf1);
	printf("%s\n", buf2);
	printf("%s\n", buf3);
	close(fp);
}

int main(){
	printf("IPC using FIFO (Named Pipe)\n");
	sendMessage();
	receiveMessage();
	return 0;
}
