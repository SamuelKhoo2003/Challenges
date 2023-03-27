#include <iostream>
#include <cmath> 
 
double mypow(double base, int exp){
    double result, oldresult1, oldresult2; 
    result = 1; 
    oldresult1 = base;
    oldresult2 = 1/base; 

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

int sumofpow(int x, int n){
    int sum, oldsum; 
    oldsum = 0; 

    for(int i = 1; i < (n+1); i++){
        sum = oldsum + mypow(x, i);
        oldsum = sum;
    }

    return sum;
}

int main(){
    int num, power; 
    std::cout << "Please enter the number you want to find the sum of." << std::endl; 
    std::cin >> num; 
    std::cout << "Please enter the power you want to find the sum up to." << std::endl; 
    std::cin >> power; 
    std::cout << "The sum of powers is: " << sumofpow(num, power) << std::endl; 
}