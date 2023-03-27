// write  aprogram that declares a vector of numbers
// using functions push_back to store a few elements in the vector. 
// print the result of the first element * (second element + third element)

#include <iostream> 
#include <vector> 

int main(){
    std::vector<int> v; 
    v.push_back(10); 
    v.push_back(20); 
    v.push_back(30); 

    int ans; 
    ans = v[0] * (v[1] + v[2]); 
    std::cout << ans << std::endl; 

}