#include <iostream> 
struct SomeStruct{
    int a; 
    int b; 

    int f(SomeStruct s2){
        return (a+s2.b) + (b*s2.a); 
    }
}; 

int main(){


SomeStruct s1;
SomeStruct s2;
int a;
int b;
int n;
a=2;
b = 3;

s1.a =4; 
s1.b = 5;
std::cin >> n;
s2.a=n; 
s2.b = 6;
std::cout << s2.f(s1) << std::endl;
}