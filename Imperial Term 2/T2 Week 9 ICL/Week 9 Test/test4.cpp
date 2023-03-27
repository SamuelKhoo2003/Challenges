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
 
int main(){
  Base* bp;
  Base ba;
  Derived1 de1;
  Derived2 de2;

  bp = &ba;
  bp->b();
  bp = &de1;
  bp->b();
  bp = &de2;
  bp->b();

}
// overriding is available in this instance
// i think it will print b b b2
// this is correct
