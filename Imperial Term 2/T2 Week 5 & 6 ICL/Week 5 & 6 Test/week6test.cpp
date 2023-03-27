#include <iostream>

struct SomeStruct{
    int a;
   
    void f(){
        a = 6;
    }
    
    int g(){
        return a;
    }

   
};

int main(){
    int a;
    SomeStruct s;
    //s.f();
    //s.a = 5;
    //std::cout << s.g() << std::endl;
}
// note this will print out 5 as s.a calls to the int a within the Somestruct and is not related to the int a in the main. 
// this can be further proven by changing the name of the variable int a in the main to int b, and this has no result on the output of the code. 


#include <iostream>

struct SomeStruct{
    int a;
   
    void f(int n){
        a = n;
    }
    
    int g(SomeStruct s2){
        return s2.a;
    }
   
};

int main(){

    SomeStruct s1;
    SomeStruct s2;
    
    //s1.f(5);
    //s2.f(6);
    
    //std::cout << //s2.g(s1) << std::endl;

}
// in this code the std::cout prints 5 as s2.g(s1) means the function g is operating for s1 and s1 has the value 5 stored in it 

#include <iostream>

struct SomeStruct{
    int f(){
        return 5;
    }
};

int z(const SomeStruct& s){
  //return s.f();
}

int main(){
    SomeStruct s;
    std::cout << z(s) << std::endl;
}
// this code returns a compiler error as the f() from Somestruct is not constant and therefore the function z doesn't work/apply 


#include <iostream>

struct SomeStruct{
    int f() const {
        return 5;
    }
};

int z(const SomeStruct& s){
  //return s.f();
}

int main(){
    SomeStruct s;
    std::cout << z(s) << std::endl;
}
// this code works and is a corrected version of the code above the prints 5 as the const is present and the function z is able to run

#include <iostream>

struct SomeStruct{
    int a;
   
    void f(int n){
        a = n;
    }
    
    int g(SomeStruct s2){
        return a - s2.a;
    }
   
};

int main(){
    int a;
    SomeStruct s1;
    SomeStruct s2;
    
    s1.f(5);
    s2.f(10);
    a = 20;
    std::cout << s2.g(s1) << std::endl;

}
// this code prints 5 not -5 as the value of s2.a is 5 and the value of a is 10 as g(s1) means it will return that value of the thing within the brackets if written as s1.a
// while if it is only return a, it will return that value of the thing before the . , so in this case s2.g so it returns a as 10