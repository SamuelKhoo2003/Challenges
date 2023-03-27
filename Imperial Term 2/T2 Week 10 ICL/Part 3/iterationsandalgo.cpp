#include <iostream>
#include <vector>
#include <algorithm> // the header for std::min_element
 
int main(){
 
    std::vector<int> numbers;
 
    numbers.push_back(30);
    numbers.push_back(10);
    numbers.push_back(20);
 
    // the function takes in input two iterators 
    // delimiting the range of the container
    // that we want to consider
    // and returns an iterator to the minimum element
    // or, if the range is empty (for example for empty containers),
    // the end of the range, in this case numbers.end()
 
    std::vector<int>::iterator minimum = std::min_element(numbers.begin(), numbers.end());
 
    std::cout << "the minimum element is:" << std::endl;
    std::cout << *minimum << std::endl;
    // in our case this will print 10
 
}