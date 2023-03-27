#include <iostream>

void f(int& a, int& b){
    b = b * 2;
}

int main(){
    int n = 0,  t = 2;
    while(t < 9){
        f(t, t);
        n++;
    }
    std::cout << n << std::endl;
}