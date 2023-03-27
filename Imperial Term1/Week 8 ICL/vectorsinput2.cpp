// modify the existing code to ask the user how many elements they want to enter and then read the elements from the user and store them in the vector. 

#include <iostream>
#include <vector>

double sum_vector(std::vector<double> vin){
 
    double sum = 0;
 
    for(int i = 0; i < vin.size(); i++){
        sum = sum + vin[i];
    }
 
    return sum;
 
}
 
int main(){
    std::vector<double> v;
    
    double n; 
    int m; 

    std::cout << "How many elements do you want to enter?" << std::endl; 
    std::cin >> m; 
    std::cout << "Please enter the elements you want to store. " << std::endl; 
    for(int i = 0; i < m; i++){
        std::cin >> n; 
        v.push_back(n);
    }
 
    std::cout << "the sum is: " << sum_vector(v) << std::endl;
 
}