//Algorithm:
//        1. Calculate the ratio (profit/cost) for each item.
//        2. Sort all products in descending order of the ratio.
//3. Initialize result=0, curr_weight= given)_weight.
//4. Repeat below steps:
//A. if the weight of the current product is less or equal to curr_weight add the value of that product in result.
//B. else add the value of the product as much as you can and break out of the loop.
//        5. Return result.


import java.util.*;

class greedy{
    static double knapsack(int profit[], int weight[], int sack) {
        double res = 0;
        TreeMap<Double, List<Integer>> tm = new TreeMap<>(Collections.reverseOrder());

        for (int i = 0; i < profit.length; i++) {
            List<Integer> list = new ArrayList<>();
            list.add(weight[i]);  // index 0
            list.add(profit[i]);  // index 1
            double ratio = (double) profit[i] / weight[i];
            tm.put(ratio, list);
        }

        for (Map.Entry<Double, List<Integer>> entry : tm.entrySet()) {
            int wt = entry.getValue().get(0);
            int val = entry.getValue().get(1);

            if (wt <= sack) {
                res += val;
                sack -= wt;
            } else {
                res += (double) val * sack / wt;
                break;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int sack = 20;
        int profit[] = {120, 100, 60};
        int weight[] = {17, 13, 8};
        System.out.println(knapsack(profit, weight, sack));
    }
}
