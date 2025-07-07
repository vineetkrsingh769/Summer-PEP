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