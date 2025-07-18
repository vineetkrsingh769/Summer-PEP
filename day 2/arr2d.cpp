// You are given a 4x4 matrix (2D array) of integers. Write a program in C++ to:
// Store the matrix using a 2D array.
// For each row, print all its elements.
// After printing the elements of a row, print the sum of that row at the end of the line in a formatted way.
// ->10 20 30 40             100
// ->11 21 31 41             104
// ->12 22 32 43             109
// ->13 23 33 43             112

#include<iostream>
using namespace std;

int main() {
    int arr[4][4] = {
        {10, 20, 30, 40},
        {11, 21, 31, 41},
        {12, 22, 32, 43},
        {13, 23, 33, 43}
    };
    for(int i = 0; i < 4; i++) {
        int sum = 0;
        for(int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
            sum += arr[i][j];
        }
        cout << "\t" << sum << endl;
    }
    return 0;
}
