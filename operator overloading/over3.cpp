#include <iostream>

class classB;

class classA{
    private:
    int a;

    public:
    classA(int value) : a(value) {} // Constructor

    friend void classB::showData(const classA &b);
};

class classB{
    public:
    void showData(const classA &b);
};

void classB::showData(const classA &b){
    std::cout << "ClassA data:: "  << b.a << std::endl;
}

int main(){
    classA objectA(10);
    classB objectB;

    objectB.showData(objectA);
    return 0;
}