#include <iostream> 
// when making a function we need to int both numbers
int max2num(int a, int b){
    int max; 

    if(a >= b){
        max = a; 
    }
    else{
        max = b;
    }
    return max; 
}

int main(){
    int x, y; 
    std::cout << "Please enter the 2 numbers you want to compare." << std::endl; 
    std::cin >> x >> y; 
    std::cout << max2num(x, y) << " is larger than or equal to the other number." << std::endl; 
}