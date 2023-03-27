//Add a reset member function for resetting the counter, i.e. to make it start again from 0. Write a main for testing.

#include <iostream> 

class Counter{
 
private: 

    int c; 

public:
 
    Counter() : c(0) {

    }

    Counter(double ic) : c(ic) {

    }
 
    void inc(){
        c++;
    }
 
    int get_count() const {
        return c;
    }

    void reset(){
        c = 0; 
    }

};

int main(){
 
    Counter c1(2);
 
    std::cout << c1.get_count() << std::endl;
 
    c1.inc();
    // ok because member function inc() is public
 
    std::cout << c1.get_count() << std::endl;

    c1.reset(); 

    std::cout << c1.get_count() << std::endl;
    
    for(int i = 0; i < 3; i++){
        c1.inc(); 
        std::cout << c1.get_count() << std::endl; 
    }
 
} 
