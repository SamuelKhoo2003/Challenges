#include <iostream>

class SomeClass{
public:
    SomeClass(int ni) : n(ni) {
        std::cout << "c" << n << std::endl;
    }

    SomeClass(const SomeClass& s) : n(s.n) {
        std::cout << "cc" << n << std::endl;
    }

    ~SomeClass(){
        std::cout << "d" << n << std::endl;
    }

private:
  int n;
};

void f(){
    std::cout << "f" << std::endl;
    SomeClass s(1);
}

int main(){
    SomeClass s1(2);
    f();
    SomeClass s2(s1);
    f();
}

// i think this will print c2 f c1 d1 cc2 f c1 d1 d2 d2
// it actually printed     c2 f c1 d1 cc2 f c1 d1 d2 d2