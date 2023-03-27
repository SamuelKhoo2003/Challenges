#include <iostream> 

int main(){
    for(int i=0; i=3; i++){
        std::cout << "*" << std::endl; 
        std::cout << i << std::endl; 
    }
    std::cout << "x" << std::endl; 
}

// this is an infinite loop as i = 3 isn't a constraint 