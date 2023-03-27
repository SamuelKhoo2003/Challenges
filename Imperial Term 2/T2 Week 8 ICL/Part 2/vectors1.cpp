#include <iostream>
#include <vector>
 
int main(){
 
    std::vector<int> v;
 
    for(int i = 0; i < 10; i++){
        v.push_back(i);
        std::cout << i << " was added"<< std::endl;
        std::cout << "size: " << v.size() << std::endl;
        std::cout << "capacity: " << v.capacity() << std::endl;
        std::cout << std::endl;
    }
 
}

// Here we observe that there is something else called “capacity”, returned by v.capacity() and that it doesn't increase after each v.push_back() 
// but instead when the previous push_back brought the size to have the same value of the capacity.