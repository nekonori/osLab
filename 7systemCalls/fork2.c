#include <unistd.h>
#include <stdio.h>

int main(){
	printf("Double fork\n");
	// calling fork
	fork(); fork();
	printf("Hello world\n");
	return 0;
}
