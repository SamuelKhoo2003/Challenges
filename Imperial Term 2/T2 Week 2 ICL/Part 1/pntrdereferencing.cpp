#include <iostream>
 
int main(){
    int a;
    int* pi; 
 
    a = 2;
    pi = &a;
 
    std::cout << a << std::endl;
    std::cout << *pi << std::endl;
    // the two printing instructions above will both print 2
 
    *pi = 3;
    // this changes the value pointed by pi, in this case a
    // *pi is the pointer to a, so setting *pi = 3 will in turn set a = 3
 
    std::cout << a << std::endl;
    std::cout << *pi << std::endl;
    // the two printing instructions above will both print 3
 
    a = 4;
 
    std::cout << a << std::endl;
    std::cout << *pi << std::endl;
    // the two printing instructions above will both print 4
 
 
}