#include <iostream>

class SomeStruct{

public:

   int a;

  SomeStruct(){

  }

  int f() const {
    return 5;
  }

};

int main(){
  SomeStruct s;
  s.a = 5;
  std::cout << s.a << std::endl;
}
