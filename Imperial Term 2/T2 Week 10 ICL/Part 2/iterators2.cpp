#include <iostream>
#include <list>
 
int main(){
 
    std::list<int> numbers;
 
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3); 
 
    std::list<int>::iterator it;
    // we declare it as being of type "iterator on a list of int"
    // this may look a bit confusing but std::list<int>::iterator is just a type
 
    // iterators are not pointers but a sort of conceptual generalisation 
    // so the operations we do on iterators have similarities with pointers
 
    it = numbers.begin();
    // we set iterator it to the beginning of the list
    while (it != numbers.end()){
        std::cout << *it << std::endl; 
        ++it; 
    }
    // we print the second element of the list

    
 
}