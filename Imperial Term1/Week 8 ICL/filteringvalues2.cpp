// write a function that takes in an input vector vin and a numerical valu t and provides an output vector vout
// this output vector should contain all the values in vin that are less than t

#include <iostream> 
#include <vector> 

void filter_v(const std::vector<double>& vin, double t, std::vector<double>& vout){ 
    for(int i = 0; i < vin.size(); i++){ 
        if(vin[i] < t){
            vout.push_back(vin[i]); 
        }
    }
    // this for loop checks all the values within vin and adds them to the empty vout function if they are less than the value t
}

int main(){
    double t = 20; 
    std::vector<double> vin, vout; 
    vin.push_back(10); 
    vin.push_back(5); 
    vin.push_back(0); 
    vin.push_back(15); 
    vin.push_back(20); 
    vin.push_back(-10); 
    vin.push_back(25); 

    filter_v(vin, t, vout); 

    std::cout << "For t = " << t; 

    std::cout << "\nvin: " << std::endl; 
    for (const int&i : vin){
        std::cout << i << " "; 
    }
    // this prints out all the elements within vin

    std::cout << "\nvout: " << std::endl; 
    for (const int&j: vout){
        std::cout << j << " "; 
    }
    // same function as above but for vout

}