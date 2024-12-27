#include <stdio.h>

char *mystrcat(char *dest, char *src) {
	int cnt = 0;
	while(*dest){
		dest++;
		cnt++;
	}
	while(*src){
		*dest++ = *src++;
		cnt++;
	}
	*dest = '\0';
	dest -= cnt;
	return dest;
}

int main(void) {
	char str[256] = "Hello ";
	char * pstr2 = "Good Bye World !!!";
	
	printf("%s\n", mystrcat(mystrcat(str, " World !!! ..."), pstr2 ));

	return 0;
}