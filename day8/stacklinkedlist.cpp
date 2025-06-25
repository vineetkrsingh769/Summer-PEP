#include<iostream>
using namespace std;

class STACK {
    class Node {
    public:
        int data;
        Node* next;

        Node(int data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    Node* top;

public:
    STACK() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) {
        top = new Node(data, top);
        cout << data << " inserted" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        } else {
            Node* temp = top;
            cout << temp->data << " deleted" << endl;
            top = top->next;
            delete temp;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        } else {
            cout << "Top element is " << top->data << endl;
        }
    }

    void size() {
        int c = 0;
        Node* temp = top;
        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }
        cout << "Size of stack is " << c << endl;
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        } else {
            Node* temp = top;
            cout << "Stack elements: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~STACK() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    STACK st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.peek();
    st.push(50);
    st.push(60);
    st.size();
    st.printStack();
    st.pop();
    st.pop();
    st.pop();
    st.printStack();
    st.pop();
    st.printStack();
    st.pop();
    st.pop(); // underflow
    st.peek();
    st.printStack();
    return 0;
}
