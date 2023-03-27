//Change the reset member function so that it starts again from the number that it started from initially (as specified in the constructor, 
//so it may or may not be 0). You will need to add member data to the class for this purpose. Write a main for testing.

#include <iostream> 

class Counter{
 
private: 

    int c; 
    int ini; 
    
public:
 
    Counter() : c(0), ini(0) {

    }

    Counter(int ic) : c(ic), ini(ic) {

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

    void reset2(){
        c = ini; 
    }

};

int main(){
 
    Counter c1(2);
 
    std::cout << c1.get_count() << std::endl;
 
    c1.inc();
    // ok because member function inc() is public
 
    std::cout << c1.get_count() << std::endl;

    c1.reset2(); 

    std::cout << c1.get_count() << std::endl;
    
    for(int i = 0; i < 3; i++){
        c1.inc(); 
        std::cout << c1.get_count() << std::endl; 
    }
 
} 
