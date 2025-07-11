Trie Data Structure:

class TrieNode {
    TrieNode []children new TrieNode[26]; // Assuming only lowercase English letters
    boolean isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = null;
        }
    }
    TrieNode root;
        static void insert(String key) {
        int len=key.lenghth();
        int index;
        TrieNode temp = root;
        for (int level = 0; level < len; level++) {
            index=key.charAt(level) - 'a';
            if (temp.children[index] == null) {
                temp.children[index] = new TrieNode();
            }
            temp = temp.children[index];
        }
        temp.isEndOfWord = true;
    }
    public static void main(String[] args) {
        String [] s={"that","then","the","them"};
        root = new TrieNode();
        for (int i = 0; i < s.length; i++) {
            insert= s[i];
        }

    }
} 
