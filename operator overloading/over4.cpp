#include <iostream>

class classB; // Forward declaration of classB

class classA {
private:
    int a;

public:
    classA(int value) : a(value) {} // Constructor

    // Friend function declaration
    friend void classB::showData(const classA &b);
};

class classB {
public:
    // Member function declaration
    void showData(const classA &b);
};

// Member function definition
void classB::showData(const classA &b) {
    std::cout << "ClassA data: " << b.a << std::endl;
}

int main() {
    classA objectA(10); // Creating an object of classA
    classB objectB;     // Creating an object of classB

    objectB.showData(objectA); // Calling showData to display private data of classA
    return 0;
}
