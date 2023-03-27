#include <iostream>
 
int main(){
    int a;
    std::cout << &a << std::endl;
}

// this code prints out the address in the memory where the variable a is stored
// note: the "&" used here does not have the same function as the & used for references and boolean logic
 