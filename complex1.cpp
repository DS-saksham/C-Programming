#include <iostream>
class complex{
    private:
    double real;
    double imag;
    public:
    complex(double, double);

    void display();
    // It will modify c2 as well
    /*complex operator+(const complex &c){
       real =real+ c.real;
         imag= imag+c.imag;
        return *this; 
    }*/
    complex operator+(const complex &c){
        return complex(real+c.real, imag + c.imag );
    }

};


complex::complex(double r, double i): real(r), imag(i){}

void complex::display(){
    std::cout<< real << "+" << imag << "i" << std::endl;
}
int main(){
    complex c1(3,6);
    complex c2(4,6);
    complex c3 = c2+c1;
    c3.display();
    c1.display();
    c2.display();
    return 0;
}
