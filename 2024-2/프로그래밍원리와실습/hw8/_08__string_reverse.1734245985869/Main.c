#include <stdio.h>

char * mystrrev(char * str) {
	int cnt = 0;
    while(str[cnt] != '\0')
        cnt++;
    int half = (cnt%2==0) ? cnt/2 : cnt/2+1;

    for(int i = 0;i<half;i++) {
        char temp = str[i];
        str[i] = str[cnt-i];
        str[cnt-1] = temp;
    }
}

int main(void) {
	char str[256];
	
	gets(str);
	
	printf("%-20s  : After Reverse >>>\n",str);
	printf("%-20s\n", mystrrev(str));

	return 0;
}