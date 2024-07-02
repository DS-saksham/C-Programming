// We are using the friend Function now

#include <iostream>

class complex
{
private:
    int real;
    int imag;

public:
    complex(int real = 0, int imag = 0)
    {
        this->real = real;
        this->imag = imag;
    }
    friend complex operator+(const complex a, const complex b);
// DEclearing a friend fuction friend function takes the entire object of a class as an arguments
     friend void display(const complex &c);
   
};

// We use the freind when we want to excess the private data members from outside the function
// This friend function is used for displaying the output
 void display(const complex &c){
    std::cout << "The real::" << c.real << std::endl;
    std::cout << "The imaginary::" << c.imag << std::endl;
 }

complex operator+(const complex a, const complex b)
{
    return complex(b.real + a.real, b.imag + a.imag);
}

int main()
{
    complex c1(3, 4), c2(4, 8), c3;
    c3 = c1 + c2;
    display(c3);
    display(c1);
    display(c2);
}
