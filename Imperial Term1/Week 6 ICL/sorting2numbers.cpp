#include <iostream>
 
// function myswap to be used 
// in sort_two_numbers below
// must be included here (beforehand)

void myswap(double& n1, double& n2){
 
    double tmp;
    tmp = n1;
    n1 = n2;
    n2 = tmp;
 
}
 
void sort_two_numbers(double& s1, double& s2){
    if(s1 > s2){
        myswap(s1, s2);
    }
    // complete this function
    // so that the output is as in the examples below
 
    // use function myswap within this function
    // (remember to change the type of the parameters to double)
}

int main(){
    double n1, n2;
    std::cout << "please enter two numbers:" << std::endl;
    std::cin >> n1 >> n2;
    sort_two_numbers(n1, n2);
    std::cout << n1 << " " << n2 << std::endl;
}
