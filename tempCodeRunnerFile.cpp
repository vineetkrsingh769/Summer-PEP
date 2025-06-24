
#include <iostream>
using namespace std;

int main() {
    float a, b;
    char op;
    cout << "first no.: ";
    cin >> a;
    cout << "second no.: ";
    cin >> b;


    cout << "operator (+, -, *, /): ";
    cin >> op;
    if (op == '+') {
        cout << "Result: " << a + b << endl;
    } else if (op == '-') {
        cout << "Result: " << a - b << endl;
    } else if (op == '*') {
        cout << "Result: " << a * b << endl;

    } else if (op == '/') {
        if (b != 0)
            cout << "Result: " << a / b << endl;
        else
            cout << "Error" << endl;
    } else {
        cout << "invalid" << endl;
    }

    return 0;
}
