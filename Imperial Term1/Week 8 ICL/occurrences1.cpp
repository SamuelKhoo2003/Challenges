// Write a program that reads from the user a number n, then reads n integer numbers from the user and stores them in a vector.
// The program then reads a number s from the user and prints how many occurrences of s are contained in the vector.

#include <iostream> 
#include <vector> 

int main(){
    int n, m, s, counter; 
    std::vector<int> store;
    std::cout << "Please enter the number of values you want to store. " << std::endl; 
    std::cin >> n;

    std::cout << "Please enter your numbers. " << std::endl; 
    for(int i = 0; i < n; i++){
        std::cin >> m; 
        store.push_back(m);
    }

    counter = 0; 

    std::cout << "Please enter the number you are looking for. " << std::endl; 
    std::cin >> s; 
    for(int j = 0; j < store.size(); j++){
        if(store[j] == s){
            counter++; 
        }
    }
    std::cout << "There are " << counter << " occurrences of the number " << s << " . " << std::endl; 
}