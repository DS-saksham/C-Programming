#include <iostream>
class array{
   public:
    int arr[10];
    int pig;
  
    /*array(){
        for(int i =0; i<10; ++i){
            arr[i] =i;
        }
    }*/

    // overloading [] operator
    array operator[](int index){
        if(index <0 || index >=10){
            std::cout << "INdex out of bounds" << std::endl;
            exit(1);
        }
        return arr[index];
    }
};
int main(){
    array a;
    a.pig =8;
    a[4] =10;
    std::cout << a[4];
    std::cout << a.pig ;
}