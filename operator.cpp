#include <iostream>
class complex {
    private:
    int real;
    int imag;
    public:
    complex(int,int);
    friend void display(const complex c);
    friend complex operator+(const complex, const complex);

};
complex::complex(int real =0,int imag =0){
    this->real =real;
    this->imag = imag;
}
void display(const complex c){
    std::cout << c.real << std::endl;
    std::cout << c.imag << std::endl;
}

complex operator+(const complex c1, const complex c2){
    return complex(c1.real+c2.real, c1.imag+c2.imag);
}


int main(){
    complex c1(5,6);
    complex c2(4,4),c3;
    c3 = c1+c2;
    display(c1);
    display(c3);
}