#include <iostream>

class SomeClass{
public:
    SomeClass(int ni) : n(ni) {
        std::cout << "c" << n << std::endl;
    }

    SomeClass(const SomeClass& s) : n(s.n) {
        std::cout << "cc" << n << std::endl;
    }

    SomeClass& operator=(const SomeClass& s){
      n = s.n; 
      std::cout << "ao" << n << std::endl;
      return *this;
    }

    ~SomeClass(){
      std::cout << "d" << n << std::endl;
    }
private:
  int n;
};

int main(){

    SomeClass s1(2);
    SomeClass s2(s1);
    SomeClass s3(3);
    s2 = s3;
    s3 = s2 = s1;
}

// i think it will print c2 cc2 c3 ao3 ao2 ao2 d2 d2 d2
// it actually printed   c2 cc2 c3 ao3 ao2 ao2 d2 d2 d2