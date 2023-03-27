//In order to enforce our abstraction (i.e. this is a counter not just any int) we can encapsulate the state by using access modifiers (also known as access specifiers). 
//Fields marked as private can't be accessed from outside the struct but member functions of the struct can access them.

#include <iostream>
 
struct Counter{
 
private:
 
    int c;
 
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
 
};
 
 
int main(){
 
    Counter c1;
 
    std::cout << c1.get_count() << std::endl;
 
    c1.inc();
    // ok because member function inc() is public
 
    std::cout << c1.get_count() << std::endl;
 
    // c1.c = -2;
    // this would not compile because the c member data is private
 
} 