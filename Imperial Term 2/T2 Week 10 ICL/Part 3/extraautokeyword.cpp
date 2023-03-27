#include <iostream>
#include <vector>
 
int main(){
 
    std::vector<int> numbers;
    auto n = 1;// with auto the type int is inferred
 
    numbers.push_back(n);
 
    n = 2;
    numbers.push_back(n);
 
    for(auto it = numbers.begin(); it != numbers.end(); ++it){
        std::cout << *it << std::endl;
    }
 
}