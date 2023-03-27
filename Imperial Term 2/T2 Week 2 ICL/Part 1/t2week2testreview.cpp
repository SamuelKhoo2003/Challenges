#include <iostream>
int main(){
    int* p;
    int n;
    
    *p = 3;
    n = 2;
    p = &n;
    
    std::cout << *p << std::endl;
}
// this has undefined behaviour as we are pointing to 3 when the pointer hasn't even been set yet

#include <iostream>
int main(){
    int* p;
    int n;
    
    *p = 3;
    p = &n;
    n = 2;
      
    std::cout << *p << std::endl;
}
// same thing here, we are pointing to 3 when the pointer hasn't even been set yet

#include <iostream>
int main(){
    int* p;
    int n;
    
    n = 2;
    p = &n;
    *p = 3;
    
    std::cout << p << std::endl;
}
// if this program is run we expect to see the hexadecimal address of n to be printed. 

#include <iostream>
int main(){
    int* p;
    int n;
    
    n = 2;
    *p = 3;
    p = &n;
    
    
    std::cout << *p << std::endl;
}
// once again we haven't set the pointer to anything yet and we are already pointing to 3, hence this will provided undefined behaviour