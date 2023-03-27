#include <iostream>

int main(){
    int* pi1;
    int* pi2;

    pi1 = new int;
    pi2 = new int;
    *pi1 = 2;
    *pi2 = 3;
    delete pi1;
    pi1 = pi2;
    std::cout << *pi1 << std::endl;
    delete pi1;
}
// this code will print 3 with no memory leaks
// initially both pi1 and pi2 assigned new memory areas
// value stored in pi1 set to 2, value stored in pi2 set to 3
// pi1 is deactivated/value is emptied (memory given back to the OS)
// pi1 is then allocated to same memory/position as pi2
// *pi1 printed gives value 3
// pi1 deactivated and emptied

int main(){
    int n;
    int* pi1;
    int* pi2;

    pi1 = new int;
    *pi1 = 2;
    pi2 = pi1;
    pi1 = &n;
    delete pi2;
}
// this program does NOT contain a memory leak 
// 1, pi1 allocated new memory area
// 2, pi1 has value 2
// 3, pi2 = pi1, both set to memory address of location 2
// 4, pi1 takes address of int n
// 5, we deactivate/delete pi2 as it is now dettached