#include <iostream>
#include <vector>

void f(std::vector<int>& v){
    v.push_back(v.size());
}

int main(){
    std::vector<int> v1;
    std::cout << v1.size() << std::endl;
    // size with nothing in it is 0 
    for(int i = 0; i < 4; i++){
        f(v1);
    }
    std::cout << v1[1] << std::endl;
}