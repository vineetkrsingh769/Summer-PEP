// Wap to convert a string to uppercase and lowercase 

// input- Hello Students thiS IS dsa CLASS
// output uppercase- HELLO STUDENTS THIS IS DSA CLASS
// output lowercase- hello students this is dsa class

#include<iostream>
#include<string>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    string upper = "", lower = "";
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (ch >= 'a' && ch <= 'z') {
            upper += ch - 32;
        } else {
            upper += ch;
        }

        if (ch >= 'A' && ch <= 'Z') {
            lower += ch + 32;
        } else {
            lower += ch;
        }
    }

    cout << "Uppercase: " << upper << endl;
    cout << "Lowercase: " << lower << endl;

    return 0;
}
