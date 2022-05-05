#include <unistd.h>
#include <stdio.h>

int main(){
	printf("Simple fork\n");
	// calling fork
	fork();
	printf("Hello world\n");
	return 0;
}
