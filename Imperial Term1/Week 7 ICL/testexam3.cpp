#include <iostream>

void f(int& a, int& b, int c){
int t;

t=b;

b=a;

c=a; 

a=t; 
}

int main(){
int a=1, b= 2, c = 3;
for(int i = 0; i< 5; i++){
f(b, c, a);
}

std::cout << a <<" " << b << " " << c << std::endl;
}