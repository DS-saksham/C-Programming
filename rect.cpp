#include <iostream>

class rectangle{
    private:
    int length;
    int breadth;
    public:
    rectangle( int length =0, int breadth =0){
        this->length = length;
        this->breadth = breadth;
    }
    void setsize(){
        std::cout << "The length is " << length << std::endl;
        std::cout << "The breadth is " << breadth << std::endl;
    }
    int getArea();
    int getPerimeter();
};
int rectangle::getArea(){
return length*breadth;
}

int rectangle::getPerimeter(){
return 2*(length+breadth);
}

int main(){
    rectangle r(5,5);
    r.setsize();
     std::cout << "The area is" << r.getArea();
    std::cout<<"\nThe perimeter is" <<r.getPerimeter();

}