#include <stdio.h>

char *mystrtok1(char *str, char delim) {
	static char *psave = 0;
	if(str != 0){
		psave = str;
		//printf("%s\n",str);
	}
	c :
	if(psave == NULL || *psave == '\0') {
		return NULL;
	}
	char *tmp = psave;
	while(*psave != '\0' && *psave != delim) {
		psave++;
	}
	if(*psave == delim){
		*psave = '\0';
		psave++;
	} else {
		psave = NULL;
	}
	if(*tmp == 0) {
		goto c;
	}
	//printf("%d",*tmp);
	return tmp;
}

int main(void) {
	char *pstr, *ptoken, delim;
	int test = 0;

	char test_str[][256] = { ",123,hello,34 56, Good.,Bye",

		" T1 T2  T3\t33   T4,4\n T5555    ",
		",,,,Token1,, Token2, Token3,,,,"};
	
	scanf("%d", &test);
	if (test > 2 || test < 0) test = 0;
	delim = test_str[test][0];
	pstr = test_str[test]+1;
	
	ptoken = mystrtok1(pstr, delim);
	
	while (ptoken) {
		printf("%s\n",ptoken);
		ptoken = mystrtok1(0, delim);		
	}

	return 0;
}