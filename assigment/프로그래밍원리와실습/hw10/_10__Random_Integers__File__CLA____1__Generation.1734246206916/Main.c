#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int * generate_numbers(int nnums) {
	int i;
	int *list = (int*)malloc(sizeof(int) * (nnums+1));
	for(i = 0;i<nnums;i++) {
		list[i] = rand();
		//printf("%d ",list[i]);
	}
	list[i] = -1;
	return list;
}
void print_nums(int *pn) {
	int i=0;
	while (pn[i] >= 0) {
		printf("%d ", pn[i++]);
		if (i%5 == 0)
			printf("\n");
	}		
}

int main(int argc, char *argv[]) {
	int myargc = 1, i;
	char my_cmd_line[1000]; 
	char *myargv[20]={"generate_numbers", NULL};
	char *token = NULL;

	gets(my_cmd_line);
	
	token = strtok(my_cmd_line, " ");
	
	while (token) {
		myargv[myargc++] = token;
		token = strtok(NULL, " ");
	}

	return mymain(myargc, myargv);
}

int mymain(int argc, char *argv[]) 
{
	int N = 10, seed = 10;
	int *rand_values = NULL;
	
	if (argc < 2) {
		printf("Usage : %s < N > [<seed>]\n\n", argv[0]);
		puts("N : Mandatory, Number of random numbers to generate");
		puts("seed : An optional seed value to seeds the random number generator, defalut = 0");
		return 0;
	}
	
 	N = atoi(argv[1]);
  seed = (argc >= 3) ? atoi(argv[2]) : 10;
  //printf("test: %d %d\n",N,seed);
	srand(seed);
	rand_values = generate_numbers(N);	
	print_nums(rand_values);

	return 0;
}