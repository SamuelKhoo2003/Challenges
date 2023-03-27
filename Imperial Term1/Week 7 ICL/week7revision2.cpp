#include <iostream> 

int main(){
    int i = 10; 

    while(i>1){
        i = i * i; 
        std::cout << "*" << std::endl; 
    }
    std::cout << "x" << std::endl; 
}