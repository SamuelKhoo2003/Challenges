#include <iostream> 
#include <cmath> 

int main(){
    int x, n, j, sum; 
    std::cout << "Please enter the number you want to find the sum of." << std::endl; 
    std::cin >> x; 
    std::cout << "Please enter the power you want to find the sum up to." << std::endl; 
    std::cin >> n; 
    j = 0; 

    for(int i = 1; i < (n+1); i++){
        sum = j + std::pow(x, i); 
        j = sum; 
    }
    std::cout << "The sum of powers is: " << sum << std::endl; 
    
}