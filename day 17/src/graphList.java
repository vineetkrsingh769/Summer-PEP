import java.util.ArrayList;

class graphList {
    static int V;
    static ArrayList<Integer>[] adj;

    graphList(int V) {  // constructor name matches class name
        this.V = V;
        adj = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new ArrayList<>();
        }
    }

    void addEdge(int src, int des) {
        adj[src].add(des);
        adj[des].add(src); // for undirected graph
    }

    void printGraph() {
        System.out.println("Adjacency List:");
        for (int i = 0; i < V; i++) {
            System.out.print(i + " -> ");
            for (int node : adj[i]) {
                System.out.print(node + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        graphList graph = new graphList(4);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(2, 1);
        graph.addEdge(2, 3);
        graph.printGraph();
    }
}
