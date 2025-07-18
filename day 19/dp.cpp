Dynamic Programming

To solve optimisation problems.
Optimisation problem: in which we have to find optimal answer.
Optimal: in which we have to calculate Min or Max.

fib(int n){
	if(n==0)
		return 1;

	return fib(n-1)+fib(n-2);
}


Steps to solve DP problem:
1. Identify if it is a dynamic programming problem.
2. Decide a state expression with the least parameters.
3. Formulate state and transition relationship.
4. Do Tabulation or Memoization.


We have 2 technique to solve DP problems:
1. Top-Down Approach (Memoization) (Recursion).
	Chaches the result of function calls.
	Recursive Implementation.
	Well Suited for problems with a relatively small set of inputs.
	Used when the subproblems have overlapping subproblems.
class Fibonacci{
	fib(int n, Map<Integer, Integer> cache){
		if(cache.containsKey(n))
			return cache.get(n);

		int result;
		if(n==0)
			result=0;
		else if(n==1)
			result=1;
		else
			result = fib(n-1, cahce) + fib(n-2, cache);

		cahche.put(n, result);
		return result;
	}

	PSVM(){
		int n=6;
		Map<Integer, Integer> cache = new HashMap<>();
		int result=fib(n, cache);
		SOP(result);
	}
}


2. Bottom-Up Approach (Tabulation) (Iterative).
	Stores the result of subproblems in a table.
	Well-Suited for problems with large set of data.
	Used when subproblems do not overlap.
class Fibonacci{
	fib(int n){
		if(n==0)
			return 0;
		else if(n==1)
			return 1;
		else{
			int table[] = new int[n+1];
			table[0]=0;
			table[1]=1;
			for (int i=2 ; i<=n ; i++)
				table[i]=table[i-1]+table[i-2];
			return trable[n];
		}
	}

	PSVM(){
		int n=6;
		int result = fib(n);
		SOP(result);
	}
}	
