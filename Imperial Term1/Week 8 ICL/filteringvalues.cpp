// write a program that reads from the user a number n, then reads n numbers from the user and stores them in a vector. 
// the program then reads an input/number t from the user and prints all numbers in the vector with a value that is less than t. 

#include <iostream> 
#include <vector> 

int main(){ 
    int n, t, max; 
    std::vector<int> storage; 
    std::cout << "Please enter the number of values you want to store." << std::endl; 
    std::cin >> n; 

    for(int i = 0; i < n; i++){
        std::cout << "Please enter a number: " << std::endl; 
        std::cin >> t; 
        storage.push_back(t); 
    }

    std::cout << "Please enter the a maximum value." << std::endl; 
    std::cin >> max; 
    std::cout << "The values less than the max value are: " << std::endl; 

    for(int j = 0; j < storage.size(); j++){
        if(storage[j] < max){
            std::cout << storage[j] << std::endl; 
        }
    }


}
