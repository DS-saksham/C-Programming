#include <iostream>

class complex{
    private:
    int real;
    int imag;

    public:
    complex(int real =0 ,int imag =0){
        this->real =real;
        this->imag = imag;
    }

    //one way of doing
    /*complex  operator+(const complex a){ 
        real += a.real;
        imag += a.imag;
        return *this ;
    }
*/ 
    complex operator+(const complex a){
        return complex(this->real+ a.real, this->imag + a.imag);
    }

    void display(){
        std::cout << "Real:: " << real << std::endl;
        std::cout << "Imaginary::" << imag << std::endl;
    }
};



int main(){
    complex c1(3,4), c2(4,8), c3;
    c3 = c1 + c2;
    c3.display();
    c2.display();
    c1.display();


}

