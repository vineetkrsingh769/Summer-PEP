import java.util.Scanner;
class graphMatrix {
    static void addEdge(int src, int des, int[][] graph) {
        graph[src][des] = 1;
        graph[des][src] = 1; // for undirected graph
    }

    static void printGraph(int[][] graph, int V) {
        System.out.println("Adjacency Matrix:");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                System.out.print(graph[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt(); // number of vertices
        int E = sc.nextInt(); // number of edges
        int[][] graph = new int[V][V];

        for (int i = 0; i < E; i++) {
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            addEdge(n1, n2, graph);
        }

        printGraph(graph, V);
    }
}

