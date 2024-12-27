#include <stdio.h>

char *mystrtok(char *str, char *delim) {
	static char *psave = 0;
	if(str != 0){
		psave = str;
	} else {
		str = psave;
	}
	if(!*psave) return NULL;
	int i,j;
	int flag = 0;
	for(;*psave;psave++){
		for(i = 0;delim[i];i++) {
			if(*psave == delim[i]) {
				flag = 1;
			}
		}
		if(flag) {
			for(;*psave;psave++) {
				for(j=0;delim[j];j++) {
					if(*psave == delim[j]) *psave = 0;
				}
				if(*psave != 0) {
					flag = 0;
					return str;
				}
			}
		}
	}
	return str;
}

int main(void) {
	char *pstr, *ptoken, *delim;
	int test = 0;

	char test_str[][256] = { "T1,T2 T3, T4  ,T5,,",", ",
		"abc\t  x\ny  z\n\nk", " \t\n",
		"#include <stdio.h>\nint\tmain(void){ int x=3;","# <>\n\t(){}=;"};
	
	scanf("%d", &test);
	if (test > 2 || test < 0) test = 0;
	pstr = test_str[2*test];
	delim = test_str[2*test+1];

	ptoken = mystrtok(pstr, delim);
	
	while (ptoken) {
		printf("%s\n",ptoken);
		ptoken = mystrtok(0, delim);		
	}
		
	return 0;
}