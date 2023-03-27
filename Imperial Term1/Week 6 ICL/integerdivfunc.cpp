#include <iostream>

void myswap(int& n1, int& n2){
    int tmp; 
    tmp = n1; 
    n1 = n2; 
    n2 = tmp; 
}

void sorttwonumbers(int& s1, int& s2){
    if(s2 > s1){
        myswap(s1, s2);
    }
}

int intdiv(int i, int j){
    int k; 
    k = i/j; 
    return k; 
}

int intrem(int i, int j){
    int l; 
    l = (i%j);
    return l;  
}

int main(){ 
    int a, b, rem; 
    std::cout << "Please enter two numbers: " << std::endl; 
    std::cin >> a >> b; 
    sorttwonumbers(a, b); 
    std::cout << "The two numbers entered are: " << std::endl; 
    std::cout << a << " " << b << std::endl; 

    rem = intrem(a, b); 

    std::cout << "The result is: " << std::endl;

    if(rem != 0){
        std::cout << a << "=" << b << "*" << intdiv(a, b) << " + " << rem << std::endl; 
    }

    else{
    std::cout << a << "=" << b << "*" << intdiv(a, b) << std::endl; 
    }
}