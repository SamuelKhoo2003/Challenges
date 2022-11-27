// write a code that checks if the vector contains an element with value n and return the index of the first occurrence of the said element if it is found

#include <iostream> 
#include <vector> 

int search_vector(int n, const std::vector<int>& vin){
    int m;

    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == n){
            m = i; 
            return m;
            
        }    
    }

    return -1;
}
// this is different from the original version I created as this version no longer uses boolean true or false statements in order to function

int main(){
    std::vector<int> v; 
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(7);
    v.push_back(10);

    std::cout << search_vector(8, v) << std::endl; 

}