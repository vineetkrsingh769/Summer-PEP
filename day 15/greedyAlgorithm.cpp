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
        for (int i=0; i<profit.length; i++){
            List<Intiger> list= new ArrayList<>();
            list.add(weight[i]);
            list.add(profit[i]);
            double temp=profit[i]/weight[i];
            tm.put(temp, list);
        }
        for (Map.Entry<Double, List<Integer>> entry : tm.entrySet()) {
            if (entry.getValue().get(1)< Sack){
                res+=(entry.getValue().get(0));
                sack -+ entry.getValue().get(1);
            } else {
                res= res+(sack*entry.getValue().get(0)/ entry.getValue().get(1));
                break;
            }
        
        }
        return res;
    }
    public static void main(String[] args) {
        int sack = 20;
        int profit[] = {120, 100 60};
        int weight[] = {17, 13, 8};
        System.out.println(knapsack(profit, weight, sack));
    }
}



Problem 2. Job Scheduling with Deadlines:
Key Points:
UniProcessor: only one processor is available.
No Preemption: Every job will not start until first job is completed.
1 Unit of time: Each job takes 1 unit of time to complete.


