#include <stdio.h>

char * mystrrev(char * str) {
	int cnt = 0;
	while(str[cnt++] != '\0');

	int mid = (cnt%2==0) ? cnt/2-1 : cnt/2;
	for(int i = 0;i<mid;i++) {
		char tmp = str[i];
		str[i] = str[cnt-2-i];
		str[cnt-2-i] = tmp;
	}
	return str;
}

int main(void) {
	char str[256];
	
	gets(str);
	
	printf("%-20s  : After Reverse >>>\n",str);
	printf("%-20s\n", mystrrev(str));

	return 0;
}