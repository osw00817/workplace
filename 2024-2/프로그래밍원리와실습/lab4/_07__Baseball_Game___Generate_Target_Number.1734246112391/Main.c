#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
/**
* @brief : generate and return a random digit in 0~9
* @return : a digit in 0~9
* @param	 : none
*/
int generate_a_digit(void) {
	return (rand()%10);
}

/**
* @brief : generate a 3-digits target integer for the puzzle
* @return : return an integer with 3 different digits in 0~9
* @param : none
*/
int generate_target_number_approach2(void) {
  int digits[] = {0,1,2,3,4,5,6,7,8,9};
	int target = 0;
	int digit1 = generate_a_digit();
  int digit2 = 0;
  int digit3 = 0;
	while((digit2 = generate_a_digit()) == digit1);
  while(1) {
		digit3 = generate_a_digit();
		if(digit3 != digit1 && digit3 != digit2)
			break;
	}
  target = digit1 * 100 + digit2 * 10 + digit3;
	//printf("%d\n",target);
	return target;
}

// Test codes below are hidden intentionally
int is_different_digits2(int num);

int main(void) {
	int num_arrays[100];
	
	int i, j, ndup = 0;
	
	srand(time(0));

	for (i=0; i<100; i++) {
		num_arrays[i] = generate_target_number_approach2();
		
		if (!is_different_digits2(num_arrays[i]))
			break;
		
		for (j=0; j<i; j++)
			if (num_arrays[j]==num_arrays[i]) {
				ndup++;		
				break;
		}
	}
	
	if (i < 100 || ndup > 20) 
		printf("Sorry, Your function does not pass the test\n");
	else
		printf("Good, Your function passes the test\n");
	
	return 0;
}

/**
* @brief : check digit duplication
* @return : return true if all digits of the number are different, false otherwise.
* @param	 : 	num - a 3-digits number to be checked for digit duplication.
*/
int is_different_digits2(int num) {
	int digits[3];
	int is_different = 1; 

	digits[0] = num%10;
	digits[1] = (num/10)%10;
	digits[2] = (num/100)%10;
	if ((digits[0] == digits[1]) ||
		(digits[0] == digits[2]) ||
		(digits[1] == digits[2]) )
		is_different = 0;

	return is_different;
}