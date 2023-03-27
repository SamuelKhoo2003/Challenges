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

    SomeClass* sp;
    f();
    sp = new SomeClass();
    f();
    delete sp;
    sp = new SomeClass(5);
    delete sp;
    SomeClass s;
}

// i think this will print f c1 d c1 f c1 d d c2 d c1 d
// it printed              f c1 d c1 f c1 d d c2 d c1 d
