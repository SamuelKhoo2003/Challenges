#include <iostream>
#include <vector>
 
// note: const before std::vector<double>
// and the & afterwards
// the & is a pass by reference, meaning any changes made to vin within the function is carried onwards/duplicated to the actual vin value
// however, the const infront of the code means that although pass by reference the vin isn't meant to be changed
double sum_vector(const std::vector<double>& vin){
 
    double sum = 0;
 
    for(int i = 0; i < vin.size(); i++){
        sum = sum + vin[i];
    }

    return sum;
 
}

// if we add vin.push_back, this function won't work as we are keeping the vector constant!
// adding one will result in an error

int main(){
    std::vector<double> v;
 
    v.push_back(3);
    v.push_back(0.5);
    v.push_back(-1);
 
    std::cout << "the sum is: " << sum_vector(v) << std::endl;
 
}