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