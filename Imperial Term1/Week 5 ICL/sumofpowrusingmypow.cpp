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
}
 
int main(){
    int x, n, j, sum; 
    std::cout << "Please enter the number you want to find the sum of." << std::endl; 
    std::cin >> x; 
    std::cout << "Please enter the power you want to find the sum up to." << std::endl; 
    std::cin >> n; 
    j = 0; 

    for(int i = 1; i < (n+1); i++){
        sum = j + mypow(x, i); 
        j = sum; 
    }
    std::cout << "The sum of powers is: " << sum << std::endl; 
}