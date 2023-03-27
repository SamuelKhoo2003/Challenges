#include <iostream> 

class SomeClass{
 
public:
 
    SomeClass(int idinput) : id(idinput) { 
      std::cout << "object with id " << id << " instantiated" << std::endl;
    }
 

    SomeClass& operator=(const SomeClass& s){
 
        std::cout << "assignment operator" << std::endl;
 
        id = s.id;
 
        return *this;

    }
 
    int get_id() const {
        return id;
    }
 
private:
 
    int id;
 
};

int main(){
    SomeClass s1(1);
    SomeClass s2(2);
    SomeClass s3(3);
 
    std::cout << "s1: " << s1.get_id() << std::endl;
    std::cout << "s2: " << s2.get_id() << std::endl;
    std::cout << "s3: " << s3.get_id() << std::endl;
 
    s3 = s2 = s1; 
    // chained assignments
    // that can be used instead of writing:
    // s2 = s1;
    // s3 = s2;
    // using member function notation this can be written as s3.operator=( s2.operator=( s1 ) );
    // s2.operator=( s1 ) must return s2
    // this is the reason for return *this; 
    // The return type we used is SomeClass& rather than SomeClass and we haven't seen other examples of returning a reference, but in this case it just makes things more efficient.

 
    std::cout << "s1: " << s1.get_id() << std::endl;
    std::cout << "s2: " << s2.get_id() << std::endl;
    std::cout << "s3: " << s3.get_id() << std::endl;
}