Problem 2: N Queens
n = 4;
output:
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 

class Main{
	static int n;
	static boolean flag;
	static int count;
	static void printBoard(int board[][]){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				System.out.print(board[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
	}

	static void solveNQueens(int board [][], int col){
		if(col==n){
			count++;
			if(!flag){
				printBoard(board);
				flag=true;
				return;
			}
		}
		for (int row=0 ; row<n ; row++){
			if(isSafe(board, row, col)){
				board[row][col]=1;
				solveNQueens(board, col+1);
				board[row][col]=0;
			}
		}
	}

	static Boolean isSafe(int board[][], int row, int col){
		//Left direction
		for(int i=0 ; i<col ; i++)
			if(board[row][i]==1)
				return false;

		//Top Left direction
		for(int i=row, j=col ; i>=0 && j>=0; i--,j--)
			if(board[i][j]==1)
				return false;

		//Bottom Left direction
		for(int i=row, j=col ; i<n && j>=0 ; i++, j--)
			if(board[i][j]==1)
				return false;

		return true;
	}

	public static void main(String [] args){
		n=4;
		int board[][] = new int[n][n];
		solveNQueens(board, 0);
		System.out.println(count);
	}
}
