#include <stdio.h>

int main(void) {
   
   return 0;
}

void printNxN(int m[NSIZE][NSIZE]) {
	int i,j;
	char lineseg[8]="-------";

	printf("+");
	for (i=0;i<NSIZE;i++) printf("%s",lineseg);
	printf("+\n");

	for (i=0;i<NSIZE;i++) {
		printf("|");
		for (j=0;j<NSIZE;j++)	printf("%6d ",m[i][j]);
		printf("|\n");
	}

	printf("+");
	for (i=0;i<NSIZE;i++) printf("%s",lineseg);
	printf("+\n");
}