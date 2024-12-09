#include <stdio.h>
#include <stdlib.h>

#define END_MARK	-1
#define MAX_SIZE	10000

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
int get_kth_largest(int* nums, int k) {
	int cnt = 0;
	int array[MAX_SIZE];

	while (nums[cnt] != END_MARK) {
		array[cnt] = nums[cnt];
		cnt++;
		if (cnt >= MAX_SIZE) break;
	}

	if (k < 1 || k > cnt)
		return -1;

	qsort(array, cnt, sizeof(int), compare);

	return array[k - 1];
}

int main(void) {
	int nums[] = { 2,3,4,5,1,5,7,12,END_MARK };
	int k = 3;

	printf("%d", get_kth_largest(nums, k));

	return 0;
}