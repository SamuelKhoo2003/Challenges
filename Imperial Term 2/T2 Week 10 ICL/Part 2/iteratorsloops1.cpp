#include <iostream>
#include <list>
 
int main(){
 
    std::list<int> numbers;
 
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3); 
 
    // so what does the termination condition mean?
    // when the iterator goes *past* the last element it becomes equal to numbers.end()
    // once again, the iterator returned by numbers.end() is not pointing to the last element
    // it points to "past the last element"
    // so while the iterator "it" is different from numbers.end() the loop keeps iterating
    // when "it" becomes equal to numbers.end() the condition becomes false and the loop terminates
 
    for(std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it){
        std::cout << *it << std::endl;
    }
 
}