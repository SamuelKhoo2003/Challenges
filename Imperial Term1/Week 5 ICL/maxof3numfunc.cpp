#include <iostream> 
// when making a function we need to int both numbers
int max2num(int a, int b, int c){
    int max; 

    if(a >= b){
        max = a;
        if(max >= c){
            max = a;
        }
        else{
            max = c;
        }
    }
    else if(b >= a){
        max = b;
        if(max >= c){
            max = b; 
        }
        else{
            max = c;
        }
    }


    return max; 
}

int main(){
    int i, j, k; 
    std::cout << "Please enter the 3 numbers you want to compare." << std::endl; 
    std::cin >> i >> j >> k; 
    std::cout << max2num(i, j, k) << " is larger than or equal to the other numbers." << std::endl; 
}