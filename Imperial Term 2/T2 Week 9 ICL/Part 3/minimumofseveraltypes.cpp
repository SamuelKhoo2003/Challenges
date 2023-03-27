//Implement and test the following function which returns the index of the minimum element in v (if v is empty it will be undefined behaviour, we don't need to consider that case).
//Test it on three different vectors respectively containing elements of type int, double and std::string (the < operator is also defined on std::string, it works according to the alphabetic order).
//Read the input for the vectors from three text files.

#include <iostream>
#include <string>
#include <vector> 
#include <fstream> 

template<typename T>
int find_minimum(const std::vector<T>& v){
    int min = 0; 
    T minelem = v[0];  

    for(int i = 1; i < v.size(); i++){
        if(v[i] < minelem){
            min = i; 
            minelem = v[i]; 
        }
    }

    return min; 
}

int main(){
    std::ifstream infile; 
    infile.open("intv.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl; 
        return EXIT_FAILURE; 
    }

    std::vector<int> integer; 
    int tmp1; 

    while(infile >> tmp1){
        integer.push_back(tmp1); 
    }

    infile.close(); 

    infile.open("doublev.txt"); 
    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl; 
        return EXIT_FAILURE; 
    }

    std::vector<double> dble; 
    double tmp2; 
    
    while(infile >> tmp2){
        dble.push_back(tmp2); 
    }

    infile.close(); 

    infile.open("stringv.txt");
    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl; 
        return EXIT_FAILURE; 
    }

    std::vector<std::string> string; 
    std::string tmp3; 

    while(infile >> tmp3){
        string.push_back(tmp3); 
    }

    infile.close(); 

    std::cout << "The minimum element in the integer list is: " << integer[find_minimum(integer)] << std::endl; 
    std::cout << "The minimum element in the double list is: " << dble[find_minimum(dble)] << std::endl; 
    std::cout << "The minimum element in the string list is: " << string[find_minimum(string)] << std::endl; 
}