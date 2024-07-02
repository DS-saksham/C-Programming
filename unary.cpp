#include <iostream>
class counter {
    public:
     int value1;
     int value2;
    counter(int value1 =0,int value2 =0): value1(value1), value2(value2) {}

    //Overloading the ++ operator
    counter operator++(){
        return counter(++value1,++value2);
      
    }
};

int main(){
    counter c(5,2);
    counter d;
    d=++c;
    std::cout << "Counter value c is " << c.value1 << std::endl;
    std::cout << "Counter value d is " <<c.value2 << std::endl;
    return 0;
}