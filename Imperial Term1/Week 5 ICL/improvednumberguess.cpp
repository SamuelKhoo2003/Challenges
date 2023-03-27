#include <iostream> 

int main(){ 
    int n, lower, upper, a, b; 
    std::string i, j;
    std::cout << "What is the range where your number lies?" << std::endl; 
    std::cin >> lower >> upper; 
    n = (lower + upper)/2;
    a = lower; 
    b = upper; 

    std::cout << "Is your number: " << n << std::endl; 
    std::cin >> i; 

    while(i != "y"){
        std::cout << "Is your number higher?" << std::endl;
        std::cin >> j;
        
        if(j == "y"){
            a = n;
            n = (a + b)/2; 
        }
        else if(j == "n"){
            b = n; 
            n = (a + b)/2; 
        }
        std::cout << "Is your number: " << n << std::endl; 
        std::cin >> i;
    
    }
    std::cout << "Your number is: " << n << "\n"; 

}