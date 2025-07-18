// // Problem 4: Length of longest substring without repeating characters
// // String= ABCDEFABCIHJKLABCD
// // output= 11

// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int lengthOfLongestSubstring(string s) {
//     unordered_map<char, int> lastSeen;
//     int maxLen = 0, start = 0;

//     for (int end = 0; end < s.length(); ++end) {
//         char current = s[end];

//         // If the character was seen and is within the current window
//         if (lastSeen.count(current) && lastSeen[current] >= start) {
//             start = lastSeen[current] + 1;
//         }

//         lastSeen[current] = end;
//         maxLen = max(maxLen, end - start + 1);
//     }

//     return maxLen;
// }

// int main() {
//     string s = "ABCDEFABCIHJKLABCD";
//     cout << "Length: " 
//          << lengthOfLongestSubstring(s) << endl;
//     return 0;
// }



// // Problem 5: search all permutation of pattern in string(count occurrences of anagram)
// // String str= BACDGABCDA
// // Pat= ABCD
// // output= 3 {0 5 6}

// // Insert pattern in map
// for(int i=0; i<m; i++){
//     char c=pat.charAt(i);
//     freqpat.put(c, freqpat.getOrDefault(c, 0) + 1);
// }

// // Inserting string in map and solution
// for(int i=0; i<m; i++){
//     char c=str.charAt(i);
//     freqstr.put(c, freqstr.getOrDefault(c, 0) + 1);
//     if(i>m){
//         char removedChar = str.charAt(i - m);
//         if(freqstr.get(removedChar) == 1) {
//             freqstr.remove(removedChar);
//         } else {
//             freqstr.put(removedChar, freqstr.get(removedChar) - 1);
//         }
//     }
//     if(i>m-1 && freqstr.equals(freqpat)){
//         count++;
//     }
// }

// import java.util.*;

// public class AnagramOccurrences {
//     public static void main(String[] args) {
//         String str = "BACDGABCDA";
//         String pat = "ABCD";

//         int n = str.length();
//         int m = pat.length();

//         Map<Character, Integer> freqpat = new HashMap<>();
//         Map<Character, Integer> freqstr = new HashMap<>();

//         // Insert pattern into freqpat map
//         for (int i = 0; i < m; i++) {
//             char c = pat.charAt(i);
//             freqpat.put(c, freqpat.getOrDefault(c, 0) + 1);
//         }

//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             // Add current character to the freqstr map
//             char c = str.charAt(i);
//             freqstr.put(c, freqstr.getOrDefault(c, 0) + 1);

//             // Remove character going out of window
//             if (i >= m) {
//                 char outChar = str.charAt(i - m);
//                 if (freqstr.get(outChar) == 1) {
//                     freqstr.remove(outChar);
//                 } else {
//                     freqstr.put(outChar, freqstr.get(outChar) - 1);
//                 }
//             }

//             // Check for match
//             if (i >= m - 1 && freqstr.equals(freqpat)) {
//                 count++;
//                 System.out.println("Anagram found at index: " + (i - m + 1));
//             }
//         }

//         System.out.println("Total count = " + count);
//     }
// }
