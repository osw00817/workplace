#include <stdio.h> 

int main(void)
{
	int a[10]={11,22,33,44,55};
	int i, j, n=5;

	scanf("%d", &j);
	// Enter your code here
	// 배열 a에 있는 값 삭제
	// 모든 배열이 앞으로 나옴
	j = (j>=1 && j<6) ? j : n;
	
	for(i=j-1;i<n-1;i++) {
		a[i]= a[i+1];
	}
	n-=1;

	for(i=0;i<n;++i) 
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;	
}