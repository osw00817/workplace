#include <stdio.h>
#include <stdlib.h>

#define END_MARK	-1
#define MAX_SIZE	10000

int compare(const void* a,const void* b){
	return (*(int*)a - *(int*)b);
}

int get_kth_largest(int *nums, int k) {
	int cnt = 0;
	while(nums[cnt] != END_MARK) {
		cnt++;
		if(cnt >= MAX_SIZE)
			break;
	}
	int *array = (int*)malloc(sizeof(int) * cnt);
	
	for(int i = 0;i<cnt;i++) {
		array[i] = nums[i];
	}
	
	if(k < 1 || k > cnt)
		return -1;
	
	qsort(array,cnt,sizeof(int),compare);
	
	return array[cnt-k];
}

int main(void) {
	
	int nums[MAX_SIZE]={0};
	int k;
	{ // Code for Test Data Generation
		int test, i;		
		scanf("%d", &test);
		
		srand(test);
		if (test == 0) {
			test = 10;
			k = 5;
			printf("Numbers to search\n");
			for (i=0; i<test; i++) {
				nums[i] = rand()%MAX_SIZE;
				printf("%10d\n",nums[i]);
			}
			nums[i] = END_MARK;
			printf("\nk = %d\n\n", k);
		}
		else {
			test = rand()%MAX_SIZE;
			for (i=0; i < test; i++)
				nums[i] = rand()%MAX_SIZE;
			nums[i] = END_MARK;
			k = rand()%MAX_SIZE+1;
		}	
	}

	printf("\nMax_K(%d) = %d, Max_K(%d) = %d, Max_K(%d) = %d\n",
		k-1, get_kth_largest(nums, k-1),
		k, get_kth_largest(nums, k),
		k+1, get_kth_largest(nums, k+1)
		);
		
	return 0;
}