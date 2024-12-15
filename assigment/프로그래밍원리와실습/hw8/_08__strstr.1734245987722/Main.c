#include <stdio.h>

char *mystrstr(char *str, char *substr) {
	if(!*substr) return str;
	
	while(*str){
		char *s1 = str,*s2 = substr;
		while(*s1 && *s2 && *s1 == *s2) {
			s1++;
			s2++;
		}
		if(!*s2) return str;
		str++;
	}
	
	return NULL;
}

void find_str(char * str, char * substr) {
	char* pos = mystrstr(str, substr);
	if(pos) 
		printf("found the string '%s' in '%s' at position: %ld\n", substr, str, pos - str);
	else
		printf("the string '%s' was not found in '%s'\n", substr, str);
}
 
int main(void) {
	char* str = "one two three";
	find_str(str, "two");
	find_str(str, "");
	find_str(str, "nine");
	find_str(str, "n");

	return 0;
}