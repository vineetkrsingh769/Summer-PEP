public class Hashing {
    public static void main(String[] args) {
        int[] hashTable = new int[10];  // Simple hash table of size 10
        int[] keys = {21, 25, 30, 42};  // Keys to insert

        for (int key : keys) {
            int index = key % 10;  // Hash function
            hashTable[index] = key;
            System.out.println("Inserted " + key + " at index " + index);
        }

        System.out.println("\nHash Table:");
        for (int i = 0; i < hashTable.length; i++) {
            System.out.println("Index " + i + ": " + hashTable[i]);
        }
    }
}
