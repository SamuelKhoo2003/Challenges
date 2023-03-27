// Change the constructor of class Counter so that it uses the initializer list as shown in Section 11.2. Write a main for testing.

#include <iostream> 

class Counter{
 
private: 

    int c; 

public:
 
    Counter() : c(0) {

    }
 
    void inc(){
        c++;
    }
 
    int get_count() const {
        return c;
    }

};

int main(){
 
    Counter c1;
 
    std::cout << c1.get_count() << std::endl;
 
    c1.inc();
    // ok because member function inc() is public
 
    std::cout << c1.get_count() << std::endl;

    for(int i = 0; i < 10; i++){
        c1.inc(); 
        std::cout << c1.get_count() << std::endl; 
    }
 
} 
