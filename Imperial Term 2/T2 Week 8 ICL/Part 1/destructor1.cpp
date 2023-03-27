#include <iostream>
 
class SomeClass{
 
public:
 
    SomeClass(int idinput) : id(idinput) { 
      std::cout << "object with id " << id << " instantiated" << std::endl;
    }
 
    // the destructor
    ~SomeClass(){
        std::cout << "object with id " << id << " going out of scope" << std::endl;
    }
 
private:
 
    int id;
 
};
 
void f(){
    SomeClass s(1);
}
 
int main(){
    SomeClass s(2);
    SomeClass s1(4); 
// without the class named e.g SomeClass (2) it will instantiated followed by going out of scope instantly, before going on to other commands. 

    SomeClass* sp;
    sp = new SomeClass(3); 
    // with dynamic memory allocation
 
    f();
    delete sp;
}

// instantiated in order 2, 3, 1 as s(2), then Someclass(3) then f()