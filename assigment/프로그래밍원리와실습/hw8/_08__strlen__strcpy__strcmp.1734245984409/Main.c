#include <stdio.h>

int mystrlen(char *str) {
	int cnt = 0;
	while(str[cnt] != '\0') {
		cnt++;
	}
	return cnt;
}

char *mystrcpy(char *dest, char *src) {
	int cnt = 0;
	while(src[cnt] != '\0') {
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
	return dest;
}

int mystrcmp(char *lhs, char *rhs) {
	int cnt = 0;
	while(lhs[cnt] != '\0' && rhs[cnt] != '\0') {
		if(lhs[cnt] != rhs[cnt]) {
			if(lhs[cnt]-rhs[cnt] < 0)
				return -1;
			else if(lhs[cnt]-rhs[cnt] > 0)
				return 1;
		}
		cnt++;
	}
	return 0;
}


int main(void) {
	char str1[256] = "Hello World !!!\n Good Day !!!";
	char str2[256] = "Hello PNU CSE !!!";
	char str3[256];
	
	printf("mystrlen(str1) = %d, mystrlen(str2) = %d\n",
				mystrlen(str1), mystrlen(str2));
	
	printf("mystrcpy(str3,str1) = %s\n", mystrcpy(str3,str1));
	
	printf("mystrcmp(str1,str3) = %d, mystrcmp(str2,str3) = %d", 
				mystrcmp(str1,str3), mystrcmp(str2,str3));
	
	return 0;
}