// write a code that checks if the vector contains an element with value n and return the index of the first occurrence of the said element if it is found

#include <iostream> 
#include <vector> 

int search_vector(int n, const std::vector<int>& vin){
    int m;
    bool c1;
    c1 = false; 
    m = -1; 

    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == n){
            c1 = true;
            m = i; 
            if(c1 = true){
                break;
            }
        }    
    }

    return m;
}

int main(){
    std::vector<int> v; 
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(7);
    v.push_back(10);

    std::cout << search_vector(9, v) << std::endl; 

}