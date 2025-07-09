Dynamic Programming

TO solve optimisation problems.
Optimisation problems: in which we have to find optimal answer.
Optimal: in which we have to calculate Min and Max.


Step to solve DP problems:
1. identify if it is a dynamic programming problem.
2. define a state expression with the least parameters.
3. Formulate state and transition reletionship.
4. Do Tabulation or Memoization.


We have 2 techniques to solve DP problems:
1. Top-Down Approach (Memoization)(Recursion).
   - Chaches the result of function calls.
   - Recursive Implementation.
   - Well Suited for problems with a relativelly small set of inputs.
   - Used when the subpeoblems have overlapping subproblems.
//   - Example: Fibonacci sequence, where the same Fibonacci numbers are calculated multiple times.
class Fibonacci {
    static int fib(int n, int[] memo) {
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }

    public static void main(String[] args) {
        int n = 10; // Example input
        int[] memo = new int[n + 1];
        Arrays.fill(memo, -1);
        System.out.println("Fibonacci of " + n + " is: " + fib(n, memo));
    }
}

2. Bottom-Up Approach (Tabulation)(Iterative).
    - 