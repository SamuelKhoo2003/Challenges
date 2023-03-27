#include <iostream>
 
int main(){
    int* pi; 
 
    pi = new int;
    // a new memory area has been allocated
    // and pi points to it
 
    pi = new int;
    // another memory area has been allocated
    // we have lost the address of the previous one
    // so it can't be deallocated anymore
    // and it will remain unavailable
    // (modern operating systems will 
    // deallocate it at the end of the program)
}


#include <iostream>
 
void f(){
    int a;
}
// using int a, each iteration the variable a in f() is allocated, but then deallocated when the function terminates

void f(){
    int* pi;
    pi = new int;
}
// if we use pointers and dynamically allocated memory, we need to "delete pi"/deallocate, or it will cause a memory leak
// we will no longer be able to access it once the function terminates, this will cause a memory leak/undefined behaviour
 
int main(){
    for(int i = 0; i < 1000; i++){
        f();
    }
}