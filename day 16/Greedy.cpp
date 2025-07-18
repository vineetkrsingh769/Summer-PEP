Greedy Algorithm

		7
	3		12
    98                      6

7+3+98 = 108
7+12+6 = 25

Greedy follows local optimization.
Feasible Solution.
Optimal Solution.
Irrevocability.


Algorithm of Greedy:
Greedy_ALgo{
	for(i=0 to n)
		x= select (a[i])
		if(feasible(x))
			solution = solution + x;
}


All greedy algorithms follow a basic rule:
1. Declare an empty result = 0
2. We make a greedy choice to select, if the choice is feasible add it to final result.
3. return the result

