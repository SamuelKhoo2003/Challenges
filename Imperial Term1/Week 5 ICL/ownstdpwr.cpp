#include <iostream>
#include <cmath> 
 
double mypow(double base, int exp){
    double result, oldresult1, oldresult2; 
    result = 1; 
    oldresult1 = base;
    oldresult2 = 1/base; 
    // we declare a variable for the result
    // (should it be initialised? to what value?)
 
    // TODO: use a for loop to implement the repeated multiplication algorithm 
    // so that at the end of the loop variable result contains base^exp
    for(int i = 1; (exp > 0) && (i < exp); i++){
        result = oldresult1 * base; 
        oldresult1 = result; 
    }

    for(int i = 1; (exp < 0) && (i < std::abs(exp)); i++){
        result = oldresult2 * (1/base); 
        oldresult2 = result; 
    }

    if(exp == 1){
        result = oldresult1; 
    }

    if(exp == -1){
        result = oldresult2; 
    }
 
    return result;
    // at the end we return the value we computed
    // we *do not print* anything in the function
}
 
int main(){
    // we test examples with integer (and non-negative) exponent
 
    std::cout << "2^3: " << mypow(2, 3) << std::endl;
    std::cout << "0.5^2: " << mypow(0.5, 2) << std::endl;
    std::cout << "1^0: " << mypow(1, 0) << std::endl;
    std::cout << "4^-1: " << mypow(4, -1) << std::endl; 
    std::cout << "2^-3: " << mypow(2,-3) << std::endl; 
    std::cout << "3^1: " << mypow(3, 1) << std::endl; 
}