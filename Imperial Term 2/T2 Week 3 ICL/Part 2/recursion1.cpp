#include <iostream> 

double mpow(double x, int n){
    if(n == 0){
        return 1; // base case 
    }
    else{
        return x * mpow(x, n - 1); // recursive call
    }
}

int main(){
    double x = 2; 
    int n = 4; 
    std::cout << mpow(2, 4) << std::endl; 
}