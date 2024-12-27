#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 

#define MAX_STONES	10000
// Global Variable - The number of current stones remaining
int gn_stones;

/**
* @brief : Determine whether a player can win when the number of stones remaining is n 
*          and the number of stones removed in the previous opponent's turn is p
* @return : return 1 if a player can win, 0 otherwise
			return 0 if n == 0
			return 1 if n < 0
* @param : n - the number of stones remaining 
*          p - the number of stones removed in the previous opponent's turn
*/
int win(int n, int p) {
	static int b_win[4][MAX_STONES+1] = {0};
	static int n_max_determined = -1;
	
	if (n<0) return 1;
	if (n_max_determined < 0) {
		//b_win[0][0] = b_win[1][0] = b_win[2][0] = b_win[3][0] = 0;
		b_win[0][1] = b_win[2][1] = b_win[3][1] = 1;
		//b_win[1][1] = 0;
		b_win[0][2] = b_win[1][2] = b_win[2][2] = b_win[3][2] = 1;
		b_win[0][3] = b_win[1][3] = b_win[2][3] = 1;
		//b_win[3][3] = 0;
		n_max_determined = 3;
	}
	
	if (n > n_max_determined) {
		int ni;
		for (ni = n_max_determined+1; ni <= n; ni++) {
			b_win[p][ni] = b_win[p][ni%4];
		}
	}		
	return b_win[p][n];
}

int Alice_Move2(int n_x) {
	for(int i = 3;i>0;i--) {
		if(i != n_x && !win(gn_stones-i,i)) {
			if(win(gn_stones,n_x)) return i;
		}
	}
	for(int i=1;i<=3;i++) {
		if(i != n_x) return i;
	}
	
	return 0;
}

/**
* @brief :  the number of stones to remove in Bob's turn
*		Possble numbers are either 1, 2 or 3
*		In this function, Bob decides his number randomly
* @return : return the decided number 
* @param : The number of stones removed by Alice in the previous turn.
*/
int Bob_Move2(int n_x) {
/*	int n_remove;
	scanf("%d",&n_remove);*/
	int n_remove = rand()%3+1;
	if (n_remove == n_x)
		n_remove = (n_x+1)%3+1;

	return n_remove;
}

/**
* @brief :  Determine whether a further move is possible or not
* @return : return 1 if a further move is possible, 0 otherwise
* @param: none
*/
int can_move2(int n_x) {
	return (gn_stones < 1 || (gn_stones == 1 && n_x == 1)) ? 0 : 1;
}

/**
* @brief :  Determine whether it is legal to remove "n_remove" stones from the current stones
* @return : return 1 if legal, 0 otherwise 
* @param : n_remove - the number of stones that a player try to remove
*	n_x - the number of stones removed by the previous turn.
*/
int is_legal_move2(int n_remove, int n_x) {
	int is_legal = 0;

	if  (n_remove <= gn_stones && n_remove <= 3 && n_remove != n_x)
		is_legal = 1;
	return is_legal;
}

int main(void) {
	int is_alice_turn = 1;
	int n_remove, n_x = 0;
	
	scanf("%d", &gn_stones);
//	gn_stones = 10;
	srand(gn_stones);

	printf("The starting number of stones %d\n", gn_stones);
	while (can_move2(n_x)) {
		if (is_alice_turn) {
			printf("Alice> ");
			n_remove = Alice_Move2(n_x);
		}
		else {
			printf("Bob>>> ");
			n_remove = Bob_Move2(n_x);
		}

		if (is_legal_move2(n_remove, n_x)) {
			printf("%d removed : [%d => %d stones remained]\n", 
				n_remove, gn_stones, gn_stones-n_remove);
			gn_stones -= n_remove;
			n_x = n_remove;
			is_alice_turn = !is_alice_turn;
		}
		else 
			printf("You can't remove %d stones, Try again\n", n_remove);		
	}

	if (is_alice_turn)
		printf("Congratulations Bob, You Win !!!");
	else
		printf("Congratulations Alice, You Win !!!");

	return 0;
}