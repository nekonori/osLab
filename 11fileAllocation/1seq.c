#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLOCKSIZE 50

int b[BLOCKSIZE+1], number, length;

void seqFileAllocation(){
	printf("Enter block no.: ");
	scanf("%d", &number);
	if (number > BLOCKSIZE)
		printf("Invalid block no.\n");
	else {
		if (b[number]==0) {
			printf("Enter length of the block: ");
			scanf("%d", &length);
			if (number+length-1 > BLOCKSIZE)
				printf("File length too large, exceeds capacity of %d\n", BLOCKSIZE); else {
				int c = 0;
				for (int i=number;i<number+length;i++) {
					printf("%d ", i);
					if(b[i]==0)
						c++;
				}
				if (c == length) {
					for(int i=number;i<number+length;i++){
						b[i] = 1;
						printf("block %d is allocated\n", i);
					}
					printf("File successfully allocated for block %d\n", number);
				} 
				else 
					printf("Given block is already used\n");
			}
		} else 
		printf("Block is already allocated, try another block\n");
	}
}

void disp(){
	for(int i=1;i<BLOCKSIZE+1;i++){
		printf("%d", b[i]);
		if(i%8==0)
			printf("\n");
	}
	printf("\n");
}

int main(){
	for (int i=1;i<BLOCKSIZE+1;i++)
		b[i] = 0;
	printf("\n\tSequential file allocation\n\n");
	printf("Initial block table:\n");
	disp();
	char ch[150];
	while(1==1){
		seqFileAllocation();
		printf("\nAfter File Allocation, Table Contents:\n");
		disp();
		printf("Enter 'y' to continue: ");
		scanf("%s", ch);
		if(strcmp(ch, "y") == 0)
			continue;
		break;
	}
	return 0;
}

