#include <iostream>
#include <list>
 
int main(){
 
    std::list<int> numbers;
 
    numbers.push_back(1);
    numbers.push_back(2);
 
    // with auto the std::list<int>::iterator type is inferred 
    // from the return value of number.begin() when "it" is initialised 
    
 
    for(auto it = numbers.begin(); it != numbers.end(); ++it){
        std::cout << *it << std::endl;
    }
 
}