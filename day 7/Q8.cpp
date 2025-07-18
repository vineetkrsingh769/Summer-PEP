/*A company has to tag its products. Each product has an associated product type which is used to tag the products. 
Product type is a sequence of lower-case letters from the English alphabet. 
The company want to have an algorithm for their system which takes the product type and outputs the tag. 
To generate the tag, pairs of adjacent characters are formed from the start of the uct type . 
From each pair the lexicographically smallest character will be removed. 
If a character will be left unpaired then that character will be taken as it is in the tag. 

Write a C++ program for the company system to find the tag for the given product. 


Input
The input consists of a string productType. representing the product type of the product.
Output
Print a string representing the tag for the given product
eg:
input: electronics
output: letois*/


#include <iostream>
using namespace std;

int main() {
    string productType;
    cin >> productType;

    string tag = ""; // Store the result tag

    for (int i = 0; i < productType.length(); i += 2) {
        if (i + 1 < productType.length()) {
            // Compare adjacent characters and take the bigger one
            if (productType[i] > productType[i + 1])
                tag += productType[i];
            else
                tag += productType[i + 1];
        } else {
            // If there's an unpaired character at the end
            tag += productType[i];
        }
    }

    cout << tag << endl;
    return 0;
}
