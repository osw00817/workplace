#include <stdio.h>
/**
* @brief : Get the minimum number of cells to repaint from the given m*n board to make a 8*8 chess board 
* @return: The minimum number of cells to repaint from the given m*n board (>=0)
         : return -1 if m < 8 or n < 8.
* @param : m - # of rows, n - # of columns, 
           board - consists of m*n cells, board[i][j] == 0(painted in black)/1(painted in white)
*/
int min_num_cell_to_repaint(int m, int n, int board[m][n]) {
	// Enter your code
	/*
	board[i][j] 
	1 -> black
	2 -> white
	*/
	int min = 65;
	int chess[8][8];
	for(int i = 0;i<8;i++) {
		for(int j = 0;j<8;j++) {
			chess[i][j] = (i%2==0) ? (j%2==0) : !(j%2==0);
		}
	}
	for(int max_x = 8; max_x<=n ;max_x++) {
		// 가로 길이 최대치
		for(int max_y = 8;max_y<=m;max_y++) {
			// 세로 길이 최대치
			int cnt1 = 0;
			int cnt2 = 0;
			int ex_x = -1;
			for(int x = max_x-8;x<max_x;x++) {
				ex_x++;
				int ex_y = -1;
				for(int y = max_y-8;y<max_y;y++) {
					ex_y++;
					if(board[y][x] != chess[ex_y][ex_x])
						cnt1++;
					if(board[y][x] == chess[ex_y][ex_x])
						cnt2++;
				}
			}
				min = (cnt1<min) ? cnt1 : ((cnt2 < min) ? cnt2 : min);
		}
		
	}
	return min;
}

int main(void) {
	int board1[8][8] = { {1,0,1,0,1,0,1,0},
						 {0,1,0,1,0,1,0,1},
						 {1,0,1,0,1,0,1,0},
						 {0,1,0,0,0,1,0,1},
						 {1,0,1,0,1,0,1,0},
						 {0,1,0,1,0,1,0,1},
						 {1,0,1,0,1,0,1,0},
						 {0,1,0,1,0,1,0,1}   
					   };
	int board2[10][13] = { {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {1,1,1,1,1,1,1,1,1,1,0,1,0},
						   {1,1,1,1,1,1,1,1,1,1,0,1,0}
					     };
	// The values of board3 are hidden on purpose
	int board3[11][13] = { {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {1,1,1,1,1,1,1,1,1,1,0,1,0},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {0,0,0,0,0,0,0,0,1,0,1,0,1},
						   {0,0,0,0,0,0,0,0,0,1,0,1,0},
						   {1,1,1,1,1,1,1,1,1,1,0,1,0},
						   {1,1,1,1,1,1,1,1,1,1,0,1,0}
					     };
	
	int option, n_repaint;
	
	scanf("%d", &option);
	
	switch (option) {
		case 1 :
			n_repaint = min_num_cell_to_repaint(8,8,board1);
			break;
		case 2 :
			n_repaint = min_num_cell_to_repaint(10,13,board2);
			break;
		default :
			n_repaint = min_num_cell_to_repaint(11,13,board3);
			break;
	}
	printf("%d\n", n_repaint);
	return 0;
}
