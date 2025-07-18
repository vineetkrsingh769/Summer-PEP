// WAP to check string is palindrome or not
// input- Madam MADAM NITIN
// output- False True True

#include<iostream>
#include<string>
using namespace std;

int main() {
    string input;
    
    // Ask user to enter a full sentence
    cout << "Enter a sentence: ";
    getline(cin, input);  // take full sentence as input

    string word = "";
    input += ' ';  // Add a space at the end to make sure the last word is processed

    // Loop through each character in the sentence
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            // Build the current word character by character
            word += input[i];
        } else {
            // When a space is found, check if the current word is a palindrome

            bool isPalin = true;
            int start = 0, end = word.length() - 1;

            // Compare characters from both ends of the word
            while (start < end) {
                if (word[start] != word[end]) {
                    isPalin = false;  // Not a palindrome
                    break;
                }
                start++;
                end--;
            }

            // Print result for this word
            if (isPalin)
                cout << "True ";
            else
                cout << "False ";

            word = "";  // Clear the word variable for the next word
        }
    }

    cout << endl;
    return 0;
}
