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
	