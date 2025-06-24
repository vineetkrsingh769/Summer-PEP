// // wap to take input from user and perform arthimatic operations.(+,-,*,/)

// #include <iostream>
// using namespace std;

// int main() {
//     float a, b;
//     char op;
//     cout << "1st no.: ";
//     cin >> a;
//     cout << "2nd no.: ";
//     cin >> b;


//     cout << "operator (+, -, *, /): ";
//     cin >> op;
//     if (op == '+') {
//         cout << "result: " << a + b << endl;
//     } else if (op == '-') {
//         cout << "result: " << a - b << endl;
//     } else if (op == '*') {
//         cout << "result: " << a * b << endl;

//     } else if (op == '/') {
//         if (b != 0)
//             cout << "result: " << a / b << endl;
//         else
//             cout << "Error" << endl;
//     } else {
//         cout << "invalid" << endl;
//     }

//     return 0;
// }



// #include <iostream>
// using namespace std;

// class Calculator {
// private:
//     float a, b;
//     char op;

// public:
//     // Method to take input
//     void getInput() {
//         cout << "1st no.: ";
//         cin >> a;
//         cout << "2nd no.: ";
//         cin >> b;
//         cout << "Operator (+, -, *, /): ";
//         cin >> op;
//     }

//     // Method to perform operation
//     void compute() {
//         if (op == '+') {
//             cout << "Result: " << a + b << endl;
//         } else if (op == '-') {
//             cout << "Result: " << a - b << endl;
//         } else if (op == '*') {
//             cout << "Result: " << a * b << endl;
//         } else if (op == '/') {
//             if (b != 0)
//                 cout << "Result: " << a / b << endl;
//             else
//                 cout << "Error: Division by zero!" << endl;
//         } else {
//             cout << "Invalid operator!" << endl;
//         }
//     }
// };

// int main() {
//     Calculator calc;  // Create object
//     calc.getInput();  // Get input
//     calc.compute();   // Perform operation

//     return 0;
// }

#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >>s;
        cout << s << endl;
    } 
    return 0;

}
 

