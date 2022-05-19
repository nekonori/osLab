#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BLOCKSIZE 50
int b[BLOCKSIZE+1], ib[BLOCKSIZE+1];
int number,length;

void indexedAllocation(){
	printf("Enter the index block no.: ");
	scanf("%d", &number);
	if(number > BLOCKSIZE)
		printf("Invalid index block no\n");
	else {
		if(b[number] == 0) {
			printf("Enter the number of files for block %d: ", number);
			scanf("%d", &length);
			printf("Enter the blocks:\n");
			for(int i=0;i<length;i++){
				printf("Files #%d: ", i+1);
				scanf("%d", &ib[i]);
			}
			int c = 0;
			for (int i=0;i<length;i++){
				if(b[ib[i]] > BLOCKSIZE){
					printf("Index block out of range\n");
					break;
				} else if (b[ib[i]] == 0)
					c++;
			}
			if(c==length){
				for(int i=0;i<length;i++){
					b[ib[i]] = 1;
					printf("Index block %d is allocated...\n", ib[i]);
				}
				printf("File allocated successfully for block %d\n", number);
			} else 
				printf("File not free for the given block");
		} else 
			printf("File / block is already allocated\n");
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
	printf("\n\tIndexed file allocation\n\n");
	printf("Initial block table:\n");
	disp();
	char ch[150];
	while(1==1){
		indexedAllocation();
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

