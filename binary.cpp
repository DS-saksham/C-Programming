#include <iostream>
class distance{
      public:
    int meters2;
    int meters1;
    distance(int meters2 =0, int meters1 =0): meters1(meters1), meters2(meters2) {}
// Here the value is stored in meters2 which is the first 
// parameter
    distance operator+(int value)const{
        return distance(meters2 +value,value+ meters1);
    }
};

int main(){
    distance d1(6,34);
    distance d2 = d1+7;
    std::cout << d2.meters1 << std::endl;
    std::cout << d2.meters2 << std::endl;
    std::cout << d1.meters2 << std::endl;
}