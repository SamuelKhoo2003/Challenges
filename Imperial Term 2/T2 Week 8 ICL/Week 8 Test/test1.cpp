#include <iostream>

class SomeClass{
public:
    SomeClass(){
        std::cout << "c1" << std::endl;
    }

    SomeClass(int n){
        std::cout << "c2" << std::endl;
    }

    ~SomeClass(){
        std::cout << "d" << std::endl;
    }
};

void f(){
    std::cout << "f" << std::endl;
    SomeClass s;
}

int main(){
    f();
    SomeClass s(2);
    f();
}
// i think this will print  c1 c2 c1 d d d
// it printed f c1 d c2 f c1 d d 
// this is because when f() it always go to the constructor first (prints out d before anything other commands are ran)
