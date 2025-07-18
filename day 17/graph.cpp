Basic Operation of Graphs:

Insertion:
Matrix
class Graph {
    static void addEdge(int src, int des, int [][]graph){
        graph[src][des] = 1;
        graph[des][src] = 1; // only in undirected graph
    }


    public static void main(String []arr){
        int V=sc.nextInet();
        int E=sc.nextInet();
        int graph[][] = new int[V+1][V+1];
        for (int i=0; i<E; i++){
            int n1=sc.nextInt();
            int n2=sc.nextInt();
            addEdge(n1, n2, graph);
        }
        printGraph(graph, V+1);
    }
}


with List:

class ListGraph {
    static int V;
    static ArrayList<Integer> adj[];
    
    ListGraph(int V) {
        this.V = V;
        adj = new ArrayList[V+1];
        for (int i = 0; i <= V; i++) {
            adj[i] = new ArrayList<>();
        }
    }
    void addEdge(int src, int des) {
        adj[src].add(des);
        adj[des].add(src); 
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            System.out.println(i+" -> ");
            System.out.println(adj[i]);
        }
    }

    public static void main(String []abc){
        ListGrahp graph = new ListGraph(4);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(2, 1);
        graph.addEdge(2, 3);
        printGraph();
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

BFS:
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











