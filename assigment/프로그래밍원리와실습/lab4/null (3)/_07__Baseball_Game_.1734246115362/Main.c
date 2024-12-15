#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ATTEMPT_LIMIT	9

// Function Prototypes
int generate_target_number(void);
int guess_number(void);
int get_match_result(int target, int guessed);
void receive_match_result(int result, int guessed);

int is_different_digits(int num);
int generate_a_digit(void);

// Implement generate_target_number()
int generate_target_number(void) {
	int target = 0,digit1 = 0,digit2 = 0,digit3 = 0;
	digit1 = generate_a_digit();
	while(1) {
		digit2 = generate_a_digit();
		if(digit1 != digit2) {
			break;
		}
	}
	while(1) {
		digit3 = generate_a_digit();
		if(digit3 != digit2 && digit3 != digit1) {
			break;
		}
	}
	target = digit1 * 100 + digit2 * 10 + digit3;
	return target;
}
// Implement get_match_result()
int get_match_result(int target,int guessed) {
	int targets[] = {target/100,(target/10)%10,target%10};
	int results[] = {guessed/100,(guessed/10)%10,guessed%10};
	int strike = 0;
	int ball = 0;
	for(int i = 0;i<3;i++) {
		if(targets[i] == results[i])
			strike++;
		if(targets[i] == results[(i+1)%3] || targets[i] == results[(i+2)%3])
			ball++;
	}
	return strike * 10 + ball;
}

int main(void) {
	int n_attempt = 0;
	int target_num, guessed_num, match_result;

	setvbuf(stdout,NULL,_IONBF, 0);

	srand(time(0));
	target_num = generate_target_number();
	do {
		printf("Attempt [%d/%d] ",++n_attempt, ATTEMPT_LIMIT);
		guessed_num = guess_number();
		match_result = get_match_result(target_num, guessed_num);
		receive_match_result(match_result, guessed_num);
	} while (n_attempt <= ATTEMPT_LIMIT && match_result != 30);

	if (match_result == 30)
		printf("Congratulation!!! You Win\n");
	else
		printf("Nice Try!!! But You Lose, The target number is %d\n", target_num);
	return 0;
}

/**
* @brief : check digit duplication
* @return : return true if all digits of the number are different, false otherwise.
* @param	 : 	num a 3-digits number to be checked for digit duplication.
*/
int is_different_digits(int num) {
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

/**
* @brief : generate and return a random digit in 0~9
* @return : a digit in 0~9
* @param	 : none
*/
int generate_a_digit(void) {
	return (rand()%10);
}

/**
* @brief : get a guessed number from the Attacker
* @return : return an integer with 3 different digits in 0~9
* @param	 : none
*/
int guess_number(void) {
	int num;
	while (1) {
		printf("Enter your guess : ");
		scanf("%d",&num);
		if (num < 1000 && is_different_digits(num)) break;
		printf("Input Error !!! Wrong number format\n");
	}
	return num;
}

/**
* @brief : notify the match result of the guessed number to the Attacker
* @return : none
* @param	 : 	result - 2-digits number for the match result, 1st digit stands for the number of strikes and 2nd digit stands for the number of balls.
			guessed - 3-digits guessed integer
*/
void receive_match_result(int result, int guessed) {
	int n_strike = result/10, n_ball = result%10;
	switch (result) {
		case 30 : printf("Congratulation !!!\n");
			break;
		case 0 : printf("Oops !!!\n");
			break;
		default : printf("Nice try !!!\n");
	}
	printf("Your guess %d is [%d] strikes and [%d] balls\n",
		guessed, n_strike, n_ball);
}
