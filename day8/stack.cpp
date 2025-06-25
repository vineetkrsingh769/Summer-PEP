#include<iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int size;

public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = value;
        cout << value << " inserted" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "stack underflow" << endl;
            return;
        }
        cout << "element " << arr[top] << " popped" << endl;
        top--;
    }

    void peek() {
        if (isEmpty())
            cout << "stack is empty" << endl;
        else
            cout << "top element is " << arr[top] << endl;
    }

    void printStack() {
        if (isEmpty())
            cout << "stack is empty" << endl;
        else {
            cout << "elements in stack are: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.peek();
    st.push(50);
    st.push(60); // stack overflow
    st.printStack();
    st.pop();
    st.pop();
    st.pop();
    st.printStack();
    st.pop();
    st.printStack();
    st.pop();
    st.pop(); // stack underflow
    st.peek();
    st.printStack();
    return 0;
}
