#include <iostream> 

class Counter{
 
public:
 
    Counter(){
        c = 0;
    }
 
    void inc(){
        c++;
    }
 
    int get_count() const {
        return c;
    }
 
private:
 
    int c;
 
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

