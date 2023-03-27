#include <iostream>
 
int main(){
    int* pi;
    pi = new int;
    delete pi;
    // ok deallocated once
 
    // delete pi;
    // not ok to deallocate again

    // we can deallocate again if it has already been deallocated
}

#include <iostream>
 
int main(){
    int* pi;
    pi = new int;
 
    int* pi2;
 
    pi2 = pi;
    // now pi2 points to the same memory area as pi
 
    delete pi;
    // ok deallocated once
 
    //delete pi2;
    // not ok to deallocate again the same memory area

    // this is because pi2 has the same memory area as pi, so since pi has been deallocated already it doesn't/can't be deallocated again
}