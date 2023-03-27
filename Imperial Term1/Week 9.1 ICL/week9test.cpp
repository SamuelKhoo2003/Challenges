#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> v;
    v.push_back("1");
    v[1] = "2";
    std::cout << v[1] << std::endl;
}
