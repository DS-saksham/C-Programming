#include <iostream>
class complex
{
private:
    int x;
    int y;

public:
    complex(int x = 0, int y = 0) : x(x), y(y) {}

    void operator-() 
    {
      x= -x;
      y= -y;
    }

    // Scalar Multiplication Using Friend Function
    friend complex operator*(int scalar, const complex &c)
    {
        return complex(scalar * c.x, scalar * c.y);
    }

    // Plus Binary Operator 
    friend complex operator+(const complex &a, const complex &b);

  void operator += (complex &c){
    this->x+= c.x;
    this->y+= c.y;
  }

  bool operator== (complex &c){
    return (x==c.x&& y==c.y);
  }
  bool operator != (complex &c){
    return !(*this ==c);
  }
  bool operator>(complex &c){
    return (x>c.x) && (y>c.y); 
  }

  complex operator ++(){
    ++x;
    ++y;
    return *this;
  }

  complex operator++(int){
    x++;
    y++;
     return *this;
  }
    friend std::ostream &operator<<(std::ostream &os, const complex &c)
    {
        os << "(" << c.x << ", " << c.y << ")";
        return os;
    }
};

 complex operator+(const complex &a, const complex &b){
    return complex( a.x+ b.x, a.y + b.y);
 }
int main()
{
    complex c(4, 5);
    complex d(3,4);
    complex e(4,2);
    -c;
    std::cout << "Unary minus " << c << std::endl;
    std::cout << "Scalar multiplication" << 3*d << std::endl;
    std::cout << "Plus Binary Operator" << d+e;
    c+=d;
    std::cout << "shorthand Operator" <<c << std::endl;
    return 0;
}