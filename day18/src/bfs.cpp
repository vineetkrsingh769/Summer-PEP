Graph

Graph Representation:
Adjacency Matrix
Adjacency List
0-1
0-2
1-2
2-3

0-------1
|     /
|   /
| /
2-------3

Adjacency Matrix		Adjacency List
  0  1  2  3			0 > 1 2
0 0  1  1  0			1 > 0 2
1 1  0  1  0			2 > 0 1 3
2 1  1  0  1			3 > 2
3 0  0  1  0

Complexity comparison of Matrix and List
Adding Egde		 O(1)       O(1)
Removing Egde		 O(1)	    O(N)
Initalize		 O(N*N)	    O(N)



Basic operation of a Graph:
Insertion:
With matrix:
import java.util.*;
class MatrixGraph{
	static void addEdges(int src, int des, int [][]graph){
		graph[src][des] = 1;
		graph[des][src] = 1; // omit this in directed graph
	}

	static void printGraph(int [][]graph, int n){
		for(int i=0 ; i<n ; i++){
			for (int j=0 ; j<n ; j++)
				System.out.print(graph[i][j]);
            	System.out.println();
        	}
	}

	public static void main(String []aargs){
        	Scanner sc = new Scanner(System.in);
		int V = sc.nextInt();
		int E = sc.nextInt();
		int graph[][] = new int[V+1][V+1];
		for (int i=0 ; i<E ; i++){
			int n1 = sc.nextInt();
			int n2 = sc.nextInt();
			addEdges(n1, n2, graph);
		}
		printGraph(graph, V+1);
	}
}

With List:
import java.util.*;
class ListGraph{
	static int V;
	static ArrayList<Integer> adj[];
	
	ListGraph(int V){
		this.V = V;
		adj = new ArrayList[V+1];

		for (int i=0 ; i<=V ; i++)
			adj[i] = new ArrayList<Integer>();
	}

	void addEdges(int src, int des){
		adj[src].add(des);
		adj[des].add(src);
	}

	void printGraph(){
		for(int i=0 ; i<=V ; i++){
			System.out.print(i+"-->");
			System.out.println(adj[i]+" ");
		}
	}

	public static void main(String []args){
		ListGraph graph = new ListGraph(4);
		graph.addEdges(0,1);
		graph.addEdges(0,2);
		graph.addEdges(2,1);
		graph.addEdges(2,3);
		graph.printGraph();
	}
}

Traversing Graph: (BFS and DFS)
	3	6
       / \   /	|
      2    1    |
       \ /   \  |
	4-------5

BFS(Breadth First Search)
	  0 1 2 3 4 5 6
Visited = F F F F F F F
List =    
Output =    3 2 1 4 6 5

DFS(Depth First Search)
	  0 1 2 3 4 5 6
Visited = F T T T T T T
Queue =   
Output =    3 2 4 1 6 5

BFS Implementation:
import java.util.*;
class ListGraph{
	static int V;
	static ArrayList<Integer> adj[];
	
	ListGraph(int V){
		this.V = V;
		adj = new ArrayList[V+1];

		for (int i=0 ; i<=V ; i++)
			adj[i] = new ArrayList<Integer>();
	}

	void addEdges(int src, int des){
		adj[src].add(des);
		adj[des].add(src);
	}

	void BFS(int x){
		boolean visited[] = new boolean[V+1];
		LinkedList<Integer> ll = new LinkedList<>();

		visited[x] = true;
		ll.add(x);
		while(ll.size!=0){
			x = ll.poll();
			System.out.print(x+" ");
			Iterator<Integer> i = arr[x].lestIterator();
			while(i.hasNext()){
				int n = i.next();
				if(!visited[n]){
					visited[n]=true;
					ll.add(n);
				}
			}
		}
	}

	public static void main(String []args){
		ListGraph graph = new ListGraph(7);
		graph.addEdges(3,2);
		graph.addEdges(3,1);
		graph.addEdges(2,4);
		graph.addEdges(4,1);
		graph.addEdges(4,5);
		graph.addEdges(1,6);
		graph.addEdges(1,5);
		graph.addEdges(6,5);
		graph.BFS(3);
	}
}

DFS(Depth First Search):
	3     6
       / \   /|
      2    1  |
       \ /   \
        4-----5
	 \
 	  7
Edges		List
3-2		1 -> 3 4 6 5
3-1		2 -> 3 4
2-4		3 -> 2 1
4-1		4 -> 2 1 5 7
4-5		5 -> 4 1 6
1-6		6 -> 1 5
1-5		7 -> 4
6-5
4-7


	  1 2 3 4 5 6 7
Visited = T T T T T T T
Stack   = 
Output  = 3 2 4 1 6 5 7

DFS Implementation:
class Graph{
	static void DFS(int v, int visited[]){
		visited[v] = true;
		System.out.print(v+" ");

		Iterator<Integer> i = arr[v].listIterator();
		while(i.hasNext()){
			int n = i.next();
			if(!visited[x]){
				DFS(n, visited);
			}
		}
	}
}


1. Degree of Graph:
	3     6
       / \   /|
      2    1  |
       \ /   \
        4-----5
Edges		Matrix
3-2		  1 2 3 4 5 6
3-1		1 0 0 0 0 1 1
2-4		2 0 0 0 1 0 0 
4-1		3 1 1 0 0 0 0
4-5		4 1 0 0 0 1 0
1-6		5 0 0 0 0 0 0
1-5		6 0 0 0 0 1 0
6-5

Indegree: 1 - 2
Outdegree: 5 - 0


static int findInDegree(int graph[][], int v){
	int count=0;
	for(int i=0 ; i<=V ; i++){
		if(graph[i][v] == 1)
			count++;
	}
}
static int findOutDegree(int graph[][], int v){
	int count=0;
	for(int i=0 ; i<=V ; i++){
		if(graph[v][i] == 1)
			count++;
	}
}



2. Transpose Graph	Graph			Transpose
A - B			  A B C D E		  A B C D E		
A - D			A 0 1 0 1 1 		A 0 0 1 0 0 
A - E			B 0 0 0 0 0		B 1 0 0 0 0 
C - A			C 1 0 0 0 0		C 0 0 0 1 0 
D - C			D 0 0 1 0 0		D 1 0 0 0 1 
E - D			E 0 0 0 1 0		E 1 0 0 0 0 

static void Tranpose(int [][]graph, int [][]transpose){
	for(int i=0 ; i<=V ; i++){
		for (int j=0 ; j<=V ; j++){
			if(graph[i][j] == 1)
				transpose[j][i] = 1;
		}
	}
}


3. Detect Cycle
static boolean dfs(int  i, boolean[] visited, boolean resStack[]){
	visited[i] = true;
	recStack[i] = true;

	for (int n : adj.get(i)){
		if(!visited[n] && dfs(n, visited, recStack))
			return true;
		else if(recStack[n])
			return true;
	}
	resStack[i] = false
	return false;
}

static boolean hasCycle(){
	boolean[] visited = new boolean[V];
	boolean[] recStack = new boolean[V];

	for (int i=0 ; i<V ; i++){
		if(!visited[i]){
			if(dfs(i, visited, recStack))
				return true;
		}
	}
	return false;
}


4. Single Source Shortest Path:		
A. Dijkstra Algorithm:  
if(current cost + (current to next cost) < defined cost)
	defined cost = current cost + (current to next cost)

				      1	| 2   3   4   5   6
1-2 = 7				      	| max max max max max
1-3 = 9	     			    1,2 | 7   9   22  max 14
1-6 = 14   			  1,2,3	| 7   9   20  max 11
2-3 = 10  			1,2,3,6	| 7   9	  20  20  11
2-4 = 15   		      1,2,3,4,6	| 7   9   20  20  11
3-4 = 11   				| 
3-6 = 2
4-5 = 6
5-6 = 9

output - 
1-2 = 7
1-2 = 9
1-4 = 20
1-5 = 20
1-6 = 11


Why Dijkstra not work on negative values:
Case 1:				Case 2:
A-B = 20			A-B = 20
A-C = 7				A-C = 7
B-C = -5			B-C = -17

B. Bellman Ford Algorithm:



Difference Between Dijkstra and Bellman Ford
Negative Value -   No		    Yes
Algorithm -        Greedy           DP
Time Cimplexity -  O(E * log V)    O(V * E)









Single Source Shortest Path:
	Dijkstra
	Bellman Ford
	Floyd Warshall
Spanning Tree
	Krushkal 
	Prims
Topological Sorting
