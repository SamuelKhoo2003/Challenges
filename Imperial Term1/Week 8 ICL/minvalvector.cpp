// write a code that returns the index of the smallest element in the vector and -1 if the vector is empty. 

#include <iostream> 
#include <vector> 

int min_vector_element(const std::vector<double>& vin){
    int j; 

    if(vin.size() > 0){
    double minnum; 
    minnum = vin[0]; 
    j = 0; 
     for(int i = 0; i < vin.size() && vin.size() > 0; i++){
        if(minnum > vin[i]){
            j = i;
        }
     }
    }

    if(vin.size() == 0){
        j = -1; 
    }
    
    return j; 

}


int main(){
    std::vector<double> m;
    m.push_back(-11);
    m.push_back(-2.5);
    m.push_back(0);
    m.push_back(-10);

    std::cout << min_vector_element(m) << std::endl; 
}

