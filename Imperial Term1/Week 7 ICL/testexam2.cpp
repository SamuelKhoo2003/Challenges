#include <iostream>

int f(int& a, int& b, int c){

a=b;

b=c;

return (a - c) * b;
}
int main(){

int a = 4, b = 2, c = 3;
b = f(b, c, a);
std::cout << c << std::endl;
}