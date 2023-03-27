//The factorial of a non-negative integer n (n!) can be defined as follows:
// n! = 1 if n is 0
// n! = n * (n-1) otherwise
#include <iostream> 

int mfact(int n){
    if(n == 0){
        return 1; 
    }
    else{
        return n * mfact(n-1); 
    }
}

int main(){
    int n = 3; 
    std::cout << mfact(n) << std::endl; 
}