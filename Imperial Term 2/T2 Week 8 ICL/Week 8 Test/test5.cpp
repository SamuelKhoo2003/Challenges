#include <iostream>

int main(){
  int* p; 
  p = new int[3];
  p[3] = 2;
  std::cout << p[3] << std::endl;
  delete[] p;
}
// this has an undefined error as we are attemtping to access out of bounds, we only has p[0, 1, 2] as only assigned 3 initially

#include <iostream>

int main(){
  int* p; 
  p = new int[3];
  p[0] = 3;
  std::cout << *p << std::endl;
  delete[] p;
}
// no undefined error, will print 3

#include <iostream>

int main(){
  int* p; 
  p = new int[3];
  delete[] p;
  p[1] = 2;
  std::cout << p[1] << std::endl;
}
//once again this has an undefined error as we try to assign a value to p which has been deleted/cleared

#include <iostream>

int main(){
  int* p1; 
  int* p2;
  p1 = new int[3];
  p1[0] = 1;
  p2 = p1;
  p1[1] = p1[0];
  p2[0] = 3;
  std::cout << p1[0] << std::endl;
  delete[] p1;
}
//this will print 3 as p2 = p1 and when p2[0] is set to 3, the same happens for p1[0] as they are essentially the same string/chain now

#include <iostream>

int main(){
  int* p1; 
  int* p2;
  int a; 
  p1 = new int[3];
  p2 = p1;
  p1[1] = 0;
  p2[0] = p1[1];
  a = p2[0];
  delete[] p1;
  delete[] p2;
  std::cout << a << std::endl;
}
// undefined behaviour because we try to delete both p1 and p2 when they are both set to each other, deleting one is suffice. 

#include <iostream>

int main(){
  int* p1; 
  int* p2;
  p1 = new int[3];
  p1[1] = 0;
  p2[0] = p1[1];
  p2[1] = p1[1];
  std::cout << p1[1] << std::endl;
  delete[] p1;
}
//this code has undefined behaviour because we haven't initialised it with p2 = new int[3], we dont know the capacity of the pointer. 