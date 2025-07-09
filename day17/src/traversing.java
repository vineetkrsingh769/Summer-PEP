//BFS:
import java.util.*;

class traversing {
    static int V;
    static ArrayList<Integer>[] adj;

    // Constructor
    traversing(int V) {
        this.V = V;
        adj = new ArrayList[V + 1];

        for (int i = 0; i <= V; i++)
            adj[i] = new ArrayList<Integer>();
    }

    void addEdges(int src, int des) {
        adj[src].add(des);
        adj[des].add(src);
    }

    void BFS(int x) {
        boolean visited[] = new boolean[V + 1];
        LinkedList<Integer> queue = new LinkedList<>();

        visited[x] = true;
        queue.add(x);

        while (!queue.isEmpty()) {
            x = queue.poll();
            System.out.print(x + " ");

            Iterator<Integer> i = adj[x].iterator();  
            while (i.hasNext()) {
                int n = i.next();
                if (!visited[n]) {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }

    public static void main(String[] args) {
        traversing graph = new traversing(7);
        graph.addEdges(3, 2);
        graph.addEdges(3, 1);
        graph.addEdges(2, 4);
        graph.addEdges(4, 1);
        graph.addEdges(4, 5);
        graph.addEdges(1, 6);
        graph.addEdges(1, 5);
        graph.addEdges(6, 5);
        graph.BFS(3);
    }
}





