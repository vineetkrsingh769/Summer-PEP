Problem 1:
Given a distance 'dist' count total number of ways to cover the distance with 1, 2 and 3 steps.

input1:
n = 3
output1: 4
1 1 1
1 2
2 1
3


input2:
n = 4
output2: 7
1 1 1 1
1 2 1
2 1 1
1 1 2
2 2
1 3
3 1


Naive Approach: 3^n
countWays(int dist){
	if(dist<0)
		return 0;
	if(dist==0)
		return 1;

	return coutWays(dist-1)+coutWays(dist-2)+coutWays(dist-1);
}

DP Approach: O(n)
countWays(int dist){
	int[] cout = new int[dist+1];
	cout[0]=1;
	if(dist>=1)
		count[1]=1;
	if(dist>=2)
		count[2]=2;

	for(int i=3 ; i<=dist ; i++)
		count[i] = count[n-1]+count[n-2]+count[n-3];

	return count[dist];
}

Count number of ways to cover distance with k steps
countWays(int d, int k){
	if(d==1)
		return 1;
	if(k==0)
		return 0;

	int dp[] = new int[d+1];
	dp[0]=1;
	int total = dp[0];
	for(int i=1 ; i<=d ; i++){
		dp[i]=total;
		if(i<k)
			total += dp[i];
		else
			total += dp[i]-dp[i-k];
	}
	return dp[d];
}



Problem 2: LCS
str1 = JKLJK
str2 = JPLK

if last char are matching skip last char from both string, and add 1;
if char is not matching make left and right recursion calls.
	left exclude last char or str1
	right exclude last char of str2

			        (JKLJK, JPLK)
			        1+(JKLJ, JPL)	
	      (JKL, JPL)				(JKLJ, JP)
	      1+(JK, JP)			 (JKL, JP)        (JKLJ, J)	
      (J, JP)	       (JK, J)               (JK,JP)  
 ("",JP)   (J,J)    (J,J)    (JK,"")   (J,JP)        (JK,J) 
	  1+("")    1+("")          ("",JP)(J,J)  (J,J)  (JK,"")
					   1+("") 1+("")

Naive Approach: 2^n
LCS(String s1, String s2, int l1, int l2){
	if(l1==0 || l2==0)
		return 0;

	if(s1.charAt(l1-1) == s2.charAt(l2-1))
		return 1+LCS(s1, s2, l1-1, l2-1);
	else
		return Math.max(LCS(s1, s2, l1-1, l2), LCS(s2, s2, l1, l2-1));
}

DP Approach: 
Time: O(n*m)
Space: O(n*m) dp + O(n+m) recursion stack
LCS(String s1, String s2, int l1, int l2, int dp[][]){
	if(l1==0 || l2==0)
		return 0;

	if(dp[l1][l2] != -1)
		return dp[l1][l2];

	if(s1.charAt(l1) == s2.charAt(l2))
		dp[l1][l2] =  1+LCS(s1, s2, l1-1, l2-1);
	else
		dp[l1][l2] =  Math.max(LCS(s1, s2, l1-1, l2), LCS(s2, s2, l1, l2-1));

	return dp[l1][l2];
}


Problem 3:
Minimum cost path to last element of matrix:

1  3  1		1 4 5
2  3  2		3 6 7
4  3  1		7 9 8

Naive Approach: O(2^(r+c))
minCost(int arr[][], int i, int j, int r, in c){
	if(i>=r || j>=c)
		return Integer.MAX_VALUE;

	if(i==r-1 && j==c-1)
		return arr[i][j];

	int right = minCost(arr, i, j+1, r, c);
	int down = minCost(arr, i+1, j, r, c);
	return arr[i][j] + Math.min(right, down);
}

DP Approach: 
Time: O(n*m)
Space: O(n*m), can be reduced to O(m)
minCost(int arr[][], int i, int j, int r, in c, int res[][]){
	res[0][0] = arr[0][0];
	
	//Updating 1st row
	for (int i=1 ; i<c ; i++)
		res[0][i] = res[0][i-1] + arr[0][i];

	//Updating 1st col
	for (int i=1 ; i<r ; i++)
		res[i][0] = res[i-1][0] + arr[i][0];

	//Update remaining matrix 
	for(int i=1 ; i<r ; i++){
		for(int j=1 ; j<c ; j++){
			res[i][j] = arr[i][j] + Math.min(res[i-1][j], res[i][j-1]);
		}
	}
	return res[r][c];
}
