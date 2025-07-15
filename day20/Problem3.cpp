

Problem 3: Rat in a MAZE
class Main{
	static boolean flag;
	static void maze(int arr[][], int r, int c, int n, int m, int count, StringBuilder res){
		if(r==n-1 && c==m-1){
			flag=true;
			System.out.println(count+" "+res);
		}

		//Checking Down Direction
		if(r+1 != n && arr[r+1][c]==1){
			maze(arr, r+1, c, n, m, count+1, res.append("D"));
			res.deleteCharAt(res.length()-1);
		}

		//Checking Right Direction
		if(c+1 != m && arr[r][c+1]==1){
			maze(arr, r, c+1, n, m, count+1, res.append("R"));
			res.deleteCharAt(res.length()-1);
		}
	}

	public static void main(String []args){
	    int arr[][]={{1, 1, 1, 0, 1, 0},
        		{1, 0, 1, 0, 0, 1},
		        {1, 0, 1, 1, 1, 0},
			{0, 1, 1, 1, 0, 1},
			{1, 1, 0, 1, 1, 1}};
		int n=arr.length;
		int m=arr[0].length;
		int count= 0;
		StringBuilder res = new StringBuilder();
		maze(arr, 0, 0, n, m, count, res);
		System.out.println(flag);
		System.out.println(res);
	}
}

