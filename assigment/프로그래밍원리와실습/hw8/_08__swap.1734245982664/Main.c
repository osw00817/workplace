#include <stdio.h>

// Revise/Modify the followin code
void swap(int *pn1, int *pn2) {
	int tn = *pn1;
	*pn1 = *pn2;
	*pn2 = tn;
	return;
}

int main(void) {
	int na = 1, nb = 99;
	
	printf("Before Swap : na = %d, nb = %d\n\n", na, nb);	
	swap(&na, &nb);
	printf("After  Swap : na = %d, nb = %d\n\n", na, nb);
	return 0;
}