#include <stdio.h>
#define MAX_NUMBER	10000


int main(void) {
	int list[MAX_NUMBER] = {0,};
	for(int i = 1;i<MAX_NUMBER;i++) {
		int sum = 0;
		int target = i;
		sum += target;
		while(target != 0) {
			sum += target%10;
			target /= 10;
		}
		if(sum <= MAX_NUMBER) {
			list[sum-1] = 1;
		}
	}
	
	for(int i = 0;i<MAX_NUMBER;i++) {
		if(list[i] == 0) {
		  printf("%d\n",i+1);
		}
	}

	return 0;
}
