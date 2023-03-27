#include <iostream> 

void myswap(std::string& t1, std::string& t2){
    std::string temp; 
    temp = t1; 
    t1 = t2;
    t2 = temp; 

}

int main(){
    std::string t1, t2; 
    
    std::cout << "Please enter two words:" << std::endl; 
    std::cin >> t1 >> t2; 

    std::cout << "You entered:" << std::endl; 
    std::cout << "word 1: " << t1 << std::endl;
    std::cout << "word 2: " << t2 << std::endl; 

    myswap(t1, t2);

    std::cout << "After swapping:" << std::endl;
    std::cout << "word 1: " << t1 << std::endl; 
    std::cout << "word 2: " << t2 << std::endl; 

}