
#include <iostream> 

int main(){
    int* p;
    int n;
    
    n = 2;
    p = &n;
    *p = 3;
    
    std::cout << p << std::endl;
    std::cout << &n << std::endl; 
}