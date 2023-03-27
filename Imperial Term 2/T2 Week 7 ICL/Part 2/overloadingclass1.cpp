//Add another constructor to class Counter (overloading, as shown in Section 11.2) so that it can start counting from a number other than 0. 
//Also in this case use the initializer list. Write a main for testing.

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

};

int main(){
 
    Counter c1(2);
 
    std::cout << c1.get_count() << std::endl;
 
    c1.inc();
    // ok because member function inc() is public
 
    std::cout << c1.get_count() << std::endl;

    for(int i = 0; i < 3; i++){
        c1.inc(); 
        std::cout << c1.get_count() << std::endl; 
    }
 
} 
