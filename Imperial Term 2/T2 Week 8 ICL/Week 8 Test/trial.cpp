#include <iostream>

int main(){
  int* p1; 
  int* p2;
  p1 = new int[3];
  p1[0] = 1;
  p2 = p1;
  p1[1] = p1[0];
  p2[0] = 3;
  std::cout << p1[1] << std::endl;
  delete[] p1;
}
//