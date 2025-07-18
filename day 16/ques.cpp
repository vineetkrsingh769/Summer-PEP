
Problem 1, Knapsack:
profit - 120 100 60
weight - 17  13  8
sack - 20

1. Greedy for Profit:
add profit: 120 & 17 weight
remaining : 3
Remaining weight * Current profit / Current Weight
3 * 100 / 13 = 23.07
Final Profit = 143.07

2. Greedy for Weight:
add profit: 60 & 8 weight
remaining weight: 12
Remaining weight * Current profit / Current Weight
12 * 100 / 13 = 92.30
Final Profit = 152.30

3. Fractional Knapsack:
120/17= 7.05, 100/13= 7.69, 60/8 = 7.5
add profit: 100 & weight 13
remaining weight: 7
Remaining weight * Current profit / Current Weight
7 * 60 / 8 = 52.5
Final Profit = 152.5


Algorithm:
1. Calculate the ratio (profit/weight) for each product,
2. Sort all products in descending order of the ratio,
3. Initialize result=0, curr_weight = given_weight,
4. Repeat below steps:
	A. if the weight of the current product is less or equal to curr_weight add the value of that product in result.
	B. else add the current product as much as you can and break out of the loop.
5. return result.

Complexity:
1. For calculating Ratio - O(N)
2. For sorting the data - O(N log N)
3. For adding products - O(N)
Final Complexity - O(N log N)


Solution:
class Main{
	static double knapsack(int profit[], int weight[], int sack){
		double res = 0;
		TreeMap<Double, List<Integer>> tm = new TreeMap<>();
		for (int i=0 ; i<profit.length ; i++){
			List <Integer> list = new ArrayList<>();
			list.add(profit[i]);
			list.add(weight[i]);
			tm.put((double)profit[i]/weight[i], list);
		}

		for (Map.Entry<Double, List<Integer>> entry : tm.descendingMap().entrySet()){
			if (entry.getValue().get(1) < sack){
				res += (entry.getValue().get(0));
				sack -= entry.getValue().get(1);
			}
			else{
				res = res+(sack*(double)entry.getValue().get(0) / entry.getValue().get(1));
				//res += sack*entry.getKey();
				break;
			}
		}
		return res;
	}

	public static void main(String[] args){
		int sack = 20;
		int profit[] = {120, 100, 60};
		int weight[] = {17, 13, 8};
		double res = knapsack(profit, weight, sack);
		System.out.println(res);
	}
}

Problem 2, Job Scheduling with Deadlines:
Key Points:
UniProcessor: only one processor will be available,
No Preemption: Next job will not start until first job is completed,
1 Unit of Time: Every job will take 1 unit of time to complete.


JobID	Deadline	Profit
A	2		55
B	1		17
C	2		12
D	1		27

Way1:
Month	Profit	JobID
1 	55 	A
2 	12 	C
Final Profit - 67

Way2:
Month	Profit	JobID
1	27	D	
2	55	A
Final Profit - 82


E.G.2.,
JobID	Deadline	Profit
A	2		100
B	1		19
C	2		27
D	1		25
E	3		15

Month	Profit	JobID
1	27	C
2	100	A
3	15	E

Algorithm:
1. Sort all jobs in descending order of profit,
2. Iterate on jobs in decreasing order of profit. For each job, do the following,
	Find a time slot i, such that slot is empty and i < deadline and i is greatest. Put the job in this slot and mark this slot filled.
	if not such i exist, i--.

Complexity: 
1. Sorting - O(N log N)
2. Adding jobs - O(N)
Final Complexity - O(N log N)


Solution:
class Main{
	public static void main(String []abc){
	    Scanner sc = new Scanner(System.in);
		int numberOfJobs = sc.nextInt();
		List<Character> jobID = new ArrayList<>();
		List<Integer> deadline = new ArrayList<>();
		List<Integer> profit = new ArrayList<>();

		for(int i=0 ; i<numberOfJobs ; i++){
			jobID.add(sc.next().charAt(0));
			deadline.add(sc.nextInt());
			profit.add(sc.nextInt());
		}

		List<Integer> profitKeep = new ArrayList(profit);
		Collections.sort(profitKeep, Collections.reverseOrder());

		int maxProfit=0;
		int[] arr = new int[numberOfJobs];
		char[] ch = new char[numberOfJobs];
		int count=0;

		while(count<numberOfJobs){
			int index = profit.indexOf(profitKeep.get(count));
			int month = deadline.get(index);
			if(arr[month-1]==0){
				arr[--month] = profit.get(index);
				ch[month] = jobID.get(index);
				maxProfit += profit.get(index);
			}
			else{
				--month;
				while(month >= 0 && month < numberOfJobs && arr[month]!=0){
					month--;
				}
				if(month>=0 && arr[month]==0){
					arr[month] = profit.get(index);
					ch[month] = jobID.get(index);
					maxProfit += profit.get(index);
				}
			}
			count++;
		}
		System.out.println("Job ID " + Arrays.toString(ch));
		System.out.println("Final Profits: " + Arrays.toString(arr));
		System.out.println("Total Profit from jobs: " + maxProfit);
	}
}



Problem 3, Coin Change

Denomination = 1 2 5 10 20 50 100 200 500 2000
Amount = 2893

2000 - 1
500 - 1
200 - 1
100 - 1
50 - 1
20 - 2
2 - 1
1 - 1


class Main{
	static LinkedHashMap<Integer, Integer> calculate(int []arr, int amt){
		int n = arr.length;
		LinkedHashMap<Integer, Integer> m = new LinkedHashMap<>();
		for(int i=n-1 ; i>=0 ; i--){
			if(amt > arr[i]){
				int x = amt/arr[i];
				amt = amt - arr[i];
				m.put(arr[i], x);
			}
		}
		return m;
	}

	public static void main(String []args){
		int []Denomination = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
		int Amount = 2893;
		LinkedHashMap<Integer, Integer> m = calculate(Denomination, Amount);
		for(Map.Entry<Integer, Integer> entry: m.entrySet())
			System.out.println(entry.getKey()+" - "+entry.getValue());
	}
}



Problem 4: Minimum number of platforms required
Arr[] = {0900, 0940, 0950, 1100, 1500, 1800};
Dep[] = {0910, 1200, 1120, 1130, 1900, 2000};

Output: 3

class Main{
	static int findPlatform(int arr[], int dep[]){
		int n = arr.legnth;
		Arrays.sort(arr);
		Arrays.sort(dep);

		int platform = 1;
		int maxPlatform = 1;
		int i=1, j=0;
		while(i<n && j<n){
			if(arr[i] <= dep[j]){
				platform++;
				i++;
			}
			else{
				platform--;
				j++;
			}
			maxPlatform = Math.max (maxPlatform ,platform)
		}
		return maxPlatform;
	}

	public static void main(String []args){
		int Arr[] = {900, 940, 950, 1100, 1500, 1800};
		int Dep[] = {910, 1200, 1120, 1130, 1900, 2000};
		int res = findPlatform(Arr, Dep);
		System.out.println(res);
	}
}



Problem 5: Form the largest number
Given an array of non-negative integers, arrange them such that they form the largest possible number.

input1: 9, 93, 24, 6
Output1: 993624

input2: 3 30 34 5 9
output2:9534330

input3: 1 20 23 4 8
output3: 8423201

class Main{
	static String largestNumber(int []nums){
		int n = nums.length;

		String []s = new String[n];
		for (int i=0; i<n ; i++)
			s[i] = String.valueOf(nums[i]);

		Arrays.sort(s, (a,b) -> (b+a).compareTo(a+b));

		String res = "";
		for (String temp: s)
			res = res+temp;

		return res;
		//StringBuilder result = new StringBuilder();
		//for(String temp: s)
		//	result.append(temp);

		//return result.toString(); 
	}

	PSVM(){
		int []nums = {9, 93, 24, 6};
		System.out.println(largestNumber(nums));
	}
}



Problem 6: Activity Selection
You are given n activities with their start and end times. Select the maximum number of activities that don't overlap, i.e., no two activities can happen at the same time.

input1:
start = {1, 3, 0, 5, 8, 5};
end   = {2, 4, 6, 7, 9, 9};

output1: 4

class Activity{
	int start, end;
	Activity(int start, int end){
		this.start = start;
		this.end = end;
	}
}
class Main{
	static maxActivity(int []start, int []end){
		int n=start.length;
		List<Activity> activities = new ArrayList<>();

		for(int i=0 ; i<n ; i++)
			activities.add(new Activity(start[i], end[i]));

		activities.sort(Comparator.comparingInt(a -> a.end));

		int count=1;
		int lastEnd = activities.get(0).end;

		for(int i=0 ; i<n ; i++){
			if(activities.get(i).start >= lastEnd){
				count++;
				lastEnd = activities.get(i).end;
			}
		}
		return count;
	}

	public static void main(String []abc){
		int start = {1, 3, 0, 5, 8, 5};
		int end = {2, 4, 6, 7, 9, 9};
		int result = maxActivity(start, end);
		System.out.println(result);
	}
}
