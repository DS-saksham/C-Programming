// Code to add 3d vextor
#include <iostream>
class vector{
    private:
    int x;
    int y;
    int z;
    public:
    // default constructor
    vector():x(0), y(0), z(0){}
    //Constructor that add value to the private data types
    vector(int x, int y, int z): x(x), y(y), z(z) {}

    // Function for displaying
    void display(){
        std::cout << "x is " << x << "\n y is:: " << y <<"\nz is " << z << std::endl;
    }

    //Operator overloading for addition
    vector operator+(const vector &v) const{
        return vector(x+v.x, y+v.y , z+v.z);
    }
};

int main(){
    vector v1(2,3,4);
    vector v2(4,5,6);
    vector v3 = v1+ v2;
    v1.display();
    v2.display();
    v3.display();
    return 0;
}
