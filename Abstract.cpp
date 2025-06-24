// #include <iostream>
// using namespace std;

// class Abstract {
// public:
//     virtual void area() = 0;
//     void display() {
//         cout << "This is a shape." << endl;
//     }
// };
// class Rectangle : public Abstract {
// public:
//     void area() override {
//         cout << "Area of rectangle: length * breadth" << endl;
//     }
// };
// class Circle : public Abstract{
// public:
//     void area() override {
//         cout << "Area of circle: π * r * r" << endl;
//     }
// };

// int main() {
//     Rectangle r;
//     Circle c;
//     r.display();
//     r.area();
//     c.display();
//     c.area();

//     return 0;
// }


#include <iostream>
using namespace std;

class Number {
public:
    int num;
    Number(int n) {
        num = n;
    }
    virtual void check() = 0;
};
class EvenOdd : public Number {
public:
    EvenOdd(int n) : Number(n) {}
    void check() override {
        if (num % 2 == 0)
            cout << num << " is Even." << endl;
        else
            cout << num << " is Odd." << endl;
    }
};

int main() {
    EvenOdd e(7);
    e.check(); 

    return 0;
}

