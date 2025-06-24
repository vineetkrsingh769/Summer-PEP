// wap to reverse a string
// input - hello students this is dsa class
// output - ssalc asd si siht stneduts olleh

#include <iostream>
using namespace std;

int main() {
    char str[100];
    cin.getline(str, 100);

    // Step 1: Reverse the whole string
    int len = 0;
    while (str[len] != '\0') len++;

    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Step 2: Reverse each word in the reversed string
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            int start = i;
            while (str[i] != ' ' && str[i] != '\0') i++;
            int end = i - 1;
            // reverse word from start to end
            while (start < end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
        } else {
            i++;
        }
    }

    cout << "Reversed output: " << str << endl;

    return 0;
}


// wap to reverse a string
// input - hello students this is dsa class
// output - olleh stneduts siht si asd ssalc     
#include<iostream>
#include<string>
using namespace std;

int main() {
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);  // take full line input

    int n = input.length();
    int start = 0;

    for (int i = 0; i <= n; i++) {
        // when space or end of string is found
        if (i == n || input[i] == ' ') {
            int end = i - 1;

            // reverse the word from start to end
            while (start < end) {
                char temp = input[start];
                input[start] = input[end];
                input[end] = temp;
                start++;
                end--;
            }

            start = i + 1;  // move to next word
        }
    }

    cout << "Reversed each word: " << input << endl;
    return 0;
}
