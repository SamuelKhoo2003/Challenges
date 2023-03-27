#include <iostream>

struct SomeStruct{

  SomeStruct(){
    
  }

  int f() const {
    return 5;
  }

};

int main(){
  SomeStruct s;
  std::cout << s.f() << std::endl;
}