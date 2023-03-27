// write a function that takes in input vin1 and vin2 and provides an output vector vout (using passing by reference)
// this output vector vout should contain all the elements in vin1 followed by all the elements in vin2

#include <iostream> 
#include <vector> 

void append_vectors(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout){
    int n, m; 
    m = vin1.size();
    n = vin2.size(); 

    for(int i = 0; i < m; i++){
        vout.push_back(vin1[i]); 
    }
    // the 1st for loop within the function adds the elements from vin1 into the empty vout vector 

    for(int i = 0; i < n; i++){
        vout.push_back(vin2[i]); 
    }
    // the 2nd for loop within the function adds the elements from vin2 onto the elements from vin1 that are already in the vout vector


}

int main(){
    std::vector<int> vin1, vin2, vout; 

    vin1.push_back(1);
    vin1.push_back(7);
    vin1.push_back(3);
    vin1.push_back(4); 

    vin2.push_back(2); 
    vin2.push_back(-2);
    vin2.push_back(19); 

    append_vectors(vin1, vin2, vout); 

    std::cout << "vin1: " << std::endl;
    for (const int&i : vin1){
        std::cout << i << " "; 
    }
    // the 3 lines of code above show how to print the elements within vin1, we can do this as vin1 isn't changed before and after

    std::cout << "\nvin2: " << std::endl; 
    for (const int&j : vin2){
        std::cout << j << " "; 
    }
    // this is the same printing function as for vin1

    std::cout << "\nvout: " << std::endl; 
    for (int k = 0; k < vout.size(); k++){
        std::cout << vout[k] << " "; 
    }
    // this prints all the elements within vout after the function is completed
}   