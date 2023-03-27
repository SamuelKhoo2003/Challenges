#include <iostream>
#include <string>
#include <utility> // this is the header for std::pair
 
int main(){
 
    std::pair<int, int> mp1; 
    // we specify the types contained in the std::pair by using <> as we do with std::vector
    mp1.first = 1;
    mp1.second = 2;
 
    std::pair<std::string, double> mp2;
    mp2.first = "hi";
    mp2.second = 0.5;
 
    // TODO: declare another instance of std::pair called mp3 and assign values to its fields
    std::pair<std::string, std::string> mp3; 
    mp3.first = "blue"; 
    mp3.second = "red"; 

    std::cout << mp1.first << " " << mp1.second << std::endl;
    std::cout << mp2.first << " " << mp2.second << std::endl;
    std::cout << mp3.first << " " << mp3.second << std::endl;
 
}