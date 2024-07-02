#include <iostream>
class point {
    public:
    int x;
    int y;
    point(){
        x=0; 
        y=0;
    }
    point(int x, int y){
        this->x =x;
        this->y =y;
    }
};
int main(){
    point p1(4,5);
    point p2;
std::cout << "\nx is::" << p1.x << std::endl;
std::cout << "\ny is::" << p1.y  << std::endl;
std::cout << "\nx is::" << p2.x << std::endl;
std::cout << "\ny is::" << p2.y  << std::endl;
}