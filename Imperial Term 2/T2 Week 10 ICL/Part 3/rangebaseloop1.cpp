#include <iostream>
#include <vector>
 
int main(){
 
    std::vector<int> numbers;
 
    numbers.push_back(1);
    numbers.push_back(2);
 
    for(const auto& e : numbers){
        std::cout << e << std::endl;
    }
 
}