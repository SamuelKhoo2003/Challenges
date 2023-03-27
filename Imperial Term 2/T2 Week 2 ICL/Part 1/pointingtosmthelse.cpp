#include <iostream>
 
int main(){
    int a, b;
    int* pi; 
 
    a = 2;
    b = 3;
    pi = &a;
 
    std::cout << a << std::endl;  // 2
    std::cout << b << std::endl;  // 3 
    std::cout << *pi << std::endl;// 2
 
    pi = &b;
    // with this line we have changed where the pointer is now allocated to, it now is tracking/linked to b's address instead of a's address
    std::cout << a << std::endl;  // 2
    std::cout << b << std::endl;  // 3 
    std::cout << *pi << std::endl;// 3
 
}