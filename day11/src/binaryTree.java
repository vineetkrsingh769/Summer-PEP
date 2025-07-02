import java.util.*;

public class binaryTree {

    // Node class defined as static so it can be used in static context
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    // Root of the binary tree
    static Node root;

    // InOrder Traversal: Left -> Root -> Right
    static void InOrder(Node temp) {
        if (temp == null)
            return;
        InOrder(temp.left);
        System.out.print(temp.data + " ");
        InOrder(temp.right);
    }

    // PreOrder Traversal: Root -> Left -> Right
    static void PreOrder(Node temp) {
        if (temp == null)
            return;
        System.out.print(temp.data + " ");
        PreOrder(temp.left);
        PreOrder(temp.right);
    }

    // PostOrder Traversal: Left -> Right -> Root
    static void PostOrder(Node temp) {
        if (temp == null)
            return;
        PostOrder(temp.left);
        PostOrder(temp.right);
        System.out.print(temp.data + " ");
    }

    // Level Order Traversal (BFS)
    static void LevelOrder(Node root) {
        if (root == null) return;

        Queue<Node> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            Node temp = q.poll();
            System.out.print(temp.data + " ");

            if (temp.left != null)
                q.add(temp.left);
            if (temp.right != null)
                q.add(temp.right);
        }
    }


    // Insert into Binary Tree (Level Order)
    static Node insert(Node root, int data) {
        if (root == null)
            return new Node(data);

        Queue<Node> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            Node temp = q.poll();

            if (temp.left == null) {
                temp.left = new Node(data);
                return root;
            } else {
                q.add(temp.left);
            }

            if (temp.right == null) {
                temp.right = new Node(data);
                return root;
            } else {
                q.add(temp.right);
            }
        }

        return root;
    }

    public static void main(String[] args) {
        // Create the binary tree
        root = new Node(10);
        root.left = new Node(7);
        root.right = new Node(9);
        root.left.left = new Node(6);
        root.left.right = new Node(8);
        root.right.left = new Node(15);
        root.right.right = new Node(5);

        System.out.print("InOrder: ");
        InOrder(root);
        System.out.println();

        System.out.print("PreOrder: ");
        PreOrder(root);
        System.out.println();

        System.out.print("PostOrder: ");
        PostOrder(root);
        System.out.println();

        System.out.print("LevelOrder: ");
        LevelOrder(root);
        System.out.println();


    }
}
