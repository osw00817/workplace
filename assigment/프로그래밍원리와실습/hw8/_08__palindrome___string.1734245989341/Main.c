#include <stdio.h> 
#include <string.h>
#include <ctype.h>

int ispalindrome(char *str) {
	int left = 0,right = strlen(str) -1;
	
	while(left < right) {
		
		if(!isalnum(str[left])) {
			left++;
			continue;
		}
		
		if(!isalnum(str[right])) {
			right--;
			continue;
		}
		
		if(tolower(str[left]) != tolower(str[right])) {
			return 0;	
		}
		
		left++;
		right--;
	}
	
	return 1;
}
int main(void) {
	char buffer[1024];

	gets(buffer);
	printf("[%s] is ", buffer);
	if (ispalindrome(buffer)) puts("a palindrome");
	else puts("not a palindrome");
	
	return 0;
}