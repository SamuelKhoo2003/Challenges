#include <iostream>
 
// this is the only different line:
void myswap(int& n1, int& n2){
 
    int tmp;
    tmp = n1;
    n1 = n2;
    n2 = tmp;
 
}
 
int main(){
    int n1, n2;
 
    std::cout << "please enter two values" << std::endl;
    std::cin >> n1 >> n2;
 
    std::cout << "you entered:" << std::endl;
    std::cout << "n1: " << n1 << std::endl;
    std::cout << "n2: " << n2 << std::endl;
 
    myswap(n1, n2);
 
    // when the function is called here
    // the n1 in myswap becomes just a different name
    // for the n1 in the main
    // (same for n2)
 
    std::cout << "after swapping the values:" << std::endl;
    std::cout << "n1: " << n1 << std::endl;
    std::cout << "n2: " << n2 << std::endl;
}


// Key Notes:
// The names of the variables and parameters have nothing special about them (e.g. instead of int& n1, int& n2 it could have been int& a, int& b)
// The & in the int& n1 has nothing to do with the boolean operator &&
// We read it as "ampersand" not as "and"
// Hence we read "int& n1" as "reference to int n1" not as "int and n1"