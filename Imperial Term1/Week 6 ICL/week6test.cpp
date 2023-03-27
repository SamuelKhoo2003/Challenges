#include <iostream>

int f(int a, int b){
    b = a;
    return b;
}

int main(){
    int a = 3, b = 2, c = 1;
    c = f(c, a);
    std::cout << a << std::endl;
}
