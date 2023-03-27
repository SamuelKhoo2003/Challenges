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

void f(const Base& inb){
  inb.b();
}
 
int main(){
  Base ba;
  Derived1 de1;
  Derived2 de2;

  f(ba);
  f(de1);
  f(de2);

}

// this prints b b b even with the const present in the void f as it is no longer virtual base