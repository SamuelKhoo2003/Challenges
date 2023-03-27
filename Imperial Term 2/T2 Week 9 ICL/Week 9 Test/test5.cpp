#include <iostream>
 
class Base{
 
public:

    virtual void b() const {
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

// without the const Base it will print b b b but with the const it will print b b b2
 
int main(){
  Base ba;
  Derived1 de1;
  Derived2 de2;

  f(ba);
  f(de1);
  f(de2);

}