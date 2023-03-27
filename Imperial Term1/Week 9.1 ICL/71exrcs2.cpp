#include <iostream>

int f()
{
    std::cout << "this is function f" << std::endl;
    return 1;
    std::cout << "printing after the first return statement" << std::endl;
    return 2;
    std::cout << "printing after the second return statement" << std::endl;
}

int main()
{
    int n = 0;
    n = f();
    std::cout << "n is: " << n << std::endl;
}

// I believe that 2 will be printed as this is where code/line makes sense up to.
// I was wrong, the number printed will be 1 as there is no need to continue on to the 2nd return if the statement is fully satisfied in the first return
// This is because as soon as a return statement is executed the function terminates.