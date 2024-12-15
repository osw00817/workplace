#include <stdio.h> 

int main(void) {
	unsigned int b, e, i;
	unsigned int x, y, sum=0;

	scanf("%d%d", &b, &e);
	scanf("%d%d", &x, &y);
	
	// Enter your code
	// x의 배수, y의 배수
	// 범위는 b이상 e이하 
	for(int i = b;i<=e;i++) {
		if(i%x==0 || i%y==0) {
			printf("%d ",i);
			sum += i;
		}
	}
	printf("\nsum == %d\n", sum);
	return 0;
}
