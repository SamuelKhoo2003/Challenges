#include <iostream>
 
class Base{
 
public:

    void b() const {
        std::cout << "b" << std::endl;
    }

    virtual ~Base(){ }
};
 
class Derived1 : public Base {
 
public: 
 
  void d1() const {
      std::cout << "d1" << std::endl;
  }
   
};

class Derived2 : public Base {
public:

  void b() const {
    std::cout << "b2" << std::endl;
  }

  void d2() const{
    std::cout << "d2" << std::endl;
  }

};
 
int main(){
  Base ba;
  Derived1 de1;
  Derived2 de2;

  ba.b();
  de1.b();
  de2.b();
 
}

// i think this will print b b b2
// it does