#include <iostream> 
#include <vector> 

int singlenumber(std::vector<int>& v){
    int ans = 0; 
    for(int a : v){
        ans ^= a;
        std::cout << "ans:" << ans << std::endl;
        std::cout << "a: " << a << std::endl; 
    }
    return ans; 

}

int main(){
    std::vector<int> v;
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);

    std::cout << singlenumber(v); 
    
}