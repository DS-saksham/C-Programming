#include <iostream>

class complex {
private:
    double real;
    double imag;

public:
    complex() : real(0), imag(0) {}
    complex(double real, double imag) : real(real), imag(imag) {}

    // Operator Overloading for addition
    complex operator+(const complex &other) const {
        return complex(this->real + other.real, this->imag + other.imag);
    }

    // Operator Overloading for subtraction
    complex operator-(const complex &other) const {
        return complex(this->real - other.real, this->imag - other.imag);
    }

    // Stream Insertion Operator Overload
    friend std::ostream& operator<<(std::ostream& os, const complex& c) {
        os << "(" << c.real << " + " << c.imag << "i)";
        return os;
    }
};

int main() {
    complex c1(3, 5);
    complex c2(45, 6);
    complex sum = c1 + c2;
    std::cout << "The sum is: " << sum << std::endl;
}
