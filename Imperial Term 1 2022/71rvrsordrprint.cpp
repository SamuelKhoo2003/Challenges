#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <vector> 

int main(){
    std::ifstream infile; 
    infile.open("71input1.txt"); 
    std::vector<int> v; 

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl; 
        return EXIT_FAILURE; 
    }

    int tmp; 

    while(infile >> tmp){
        v.push_back(tmp); 
    }
    
    infile.close(); 

    int n = v.size() - 1;
    // v.size()-1 is necessary as the v.size is actually 1 larger than the largest index value within the function as index starts from 0, while v.size starts from 1
    for(int i = n; i >= 0; i--){
        std::cout << v[i] << std::endl; 
    }
}