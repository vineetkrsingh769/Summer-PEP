Tree DATA STRUCTURE

Binary Tree 

                6
        5               4
    3       1       2       7          


// Node: The fundamental part of a binary tree, which contains data and link to left and right child.
// Root: The topmost noe in your tree,ehich has no parent.4
// Parent NOde: A node that has at least one child
// Child Node: A node that is descendent of another node
// Leaf Node: A node that has not have any child nodes.
// Internal NOde: A node that has at least one child except root.


Properties of Binary Tree:
The Maximum number of nodes at level L of a binary tree can be 2 power L.
Maximum number of nodes in binary tree of height H= 2 power (H+1) - 1.


Basic Operations on Binary Tree:
Insert a node
Delete a node
Search a node
Traverse a node
Update a node


                6
        5               4
    3       1       2       7  

Traversal: 
DFS (Depth First Search):
        InOrder Traversal: Left, Root, Right -> 3516247
        PreOrder Traversal: Root, Left, Right -> 6531247
        PostOrder Traversal: Left, Right, Root -> 3157246

BFS (Breadth First Search): 
        Level Order Traversal: 6, 5, 4, 3, 1, 2, 7
        Zigzag Level Order Traversal: 6, 4, 5, 7, 2, 1, 3

Implementation of Tree:

class Main{
    class Node{
        int data;
        Node* left, right;
        Node(int data){
            this.data = data;
            left = right = null;
        }
    }
    static Node root;
    static Node root;

    void InOrder(Node temp) {
        if(temp=null)
            return;
        InOrder(temp.left);
        System.out.print(temp.data + " ");
        InOrder(temp.right);
    }
    void PreOrder(Node temp) {
        if(temp==null)
            return;
        System.out.print(temp.data + " ");
        PreOrder(temp.left);
        PreOrder(temp.right);
    }
    void PostOrder(Node temp) {
        if(temp==null)
            return;
        PostOrder(temp.left);
        PostOrder(temp.right);
        System.out.print(temp.data + " ");
    }
    LevelOrder(Node root){
        Queue<Node> queue = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int levelSize = q.size();
            for(int i=0; i<levelSize; i++) {
                Node temp = queue.poll();
                System.out.print(tempNode.data);
                
                if(temp.left != null) {
                    q.add(temp.left);
                }
                if(temp.right != null) {
                    q.add(temp.right);
                }
            }
        }
    }

    public static void main(string []args) {
        root= new Node(10);
        root.left.left = new Node(7);
        root.left.right = new Node(6);
        root.right = new Node(9);
        root.right.left = new Node(15);
        root.right.right = new Node(8);
        InOrder();
        PreOrder();
        PostOrder();
        LevelOrder();

    }
}

