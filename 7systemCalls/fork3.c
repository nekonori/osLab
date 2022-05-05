#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("Triple fork\n");
	// calling fork
	fork();
	fork();
	fork();
	printf("Hello world\n");
	return 0;
}
