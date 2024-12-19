#include <stdio.h>
/**
* @brief : Get the minimum number of cells to repaint from the given m*n board to make a 8*8 chess board 
* @return: The minimum number of cells to repaint from the given m*n board (>=0)
         : return -1 if m < 8 or n < 8.
* @param : m - # of rows, n - # of columns, 
           board - consists of m*n cells, board[i][j] == 0(painted in black)/1(painted in white)
*/
int min_num_cell_to_repaint(int m, int n, int board[m][n]) {
	int answer[8][8] = {
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
    }; 
    int min = 64;
    for(int i = 8;i<=m;i++) {
        for(int j = 8;j<=n;j++) {
            int count1 = 0;
            int count2 = 0;
            int garo_sample = -1;
            for(int garo = i-8;garo < i;garo++) {
                garo_sample++;
                int sero_sample = -1;
                for(int sero=j-8;sero< j;sero++) {
                    sero_sample++;
                    count1 += (board[garo][sero] == answer[garo_sample][sero_sample]);
                    count2 += (board[garo][sero] != answer[garo_sample][sero_sample]);
                }
            }
            printf("%d %d\n",count1,count2);
            if(min > count1)
                min = count1;
            if(min > count2)
                min = count2;
        }
    }
    /*
    //0 1 2 3 4 5 6 7
    0 1 0 1 0 1 0 1
    1 0 1 0 1 0 1 0
    */
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
