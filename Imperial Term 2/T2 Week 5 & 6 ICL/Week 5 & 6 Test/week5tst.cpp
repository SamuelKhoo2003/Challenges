#include <iostream>

int f(int n){
    if(n == 0){
        return 1;
    }
    else if((n % 2) == 0){
        return f(n - 1);
    }
    else{
        return n + f(n - 1);
    }
}

int main(){
    int n;
    std::cin >> n;
    std::cout << f(n) << std::endl;
}

// n = 5 for you to print out 10