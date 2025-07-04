Greedy Algorithm

                7
            3        12
        98                  6

7+3+98=108  accoding to the greedy algorithm
7+12+6=25 


3.

Algorithm:
1. Calculate the ratio (profit/cost) for each item.
2. Sort all products in descending order of the ratio.
3. Initialize result=0, curr_weight= given)_weight.
4. Repeat below steps:
        A. if the weight of the current product is less or equal to curr_weight add the value of that product in result.
        B. else add the value of the product as much as you can and break out of the loop.
5. Return result.

Solution.
class Main{
    static double knapsack(int profit[], int weight[], int sack){
        double res=0;
        TreeMap<Double, List<Integer>> tm=new TreeMap<>();
        for
    }
}

