#include <iostream>
class complex{
    private:
         double real;
         double imag;

    public:
        complex():real(0),imag(0){}
        complex(double real,double imag):real(real),imag(imag){}


    //Operator Overloding for addition
    complex operator+(const complex &other)const{
        return complex(this->real + other.real, this->imag + other.imag);
    }

    //Operator overloding for substraction
    complex operator-(const complex &other)const{
        return complex(this->real-other.real, this->imag-other.imag);
    }
     void display(){
        std::cout << "real is:: " << real << std::endl; 
        std::cout << "Imaginary is:: " << imag << std::endl;
    }
};


int main(){
    complex c1(3,5);
    complex c2(45,6);
    complex sum = c1+ c2;
sum.display();
}