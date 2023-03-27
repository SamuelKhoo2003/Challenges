#include <iostream>
#include <string>
 
template<typename T1, typename T2>
class MPair{
public:
    T1 first;
    T2 second;
};
 
int main(){
 
    MPair<int, int> mp1; 
    // we specify the type contained in the MPair by using <> as we do with std::vector
    mp1.first = 1;
    mp1.second = 2;

    MPair<std::string, double> mp2; 
    mp2.first = "hi"; 
    mp2.second = 0.5; 

    MPair<std::string, std::string> mp3; 
    mp3.first = "blue"; 
    mp3.second = "red"; 
    
 
    // TODO: declare another instance of MPair called mp2 and assign values to its fields
    // TODO: declare another instance of MPair called mp3 and assign values to its fields
 
    std::cout << mp1.first << " " << mp1.second << std::endl;
    std::cout << mp2.first << " " << mp2.second << std::endl;
    std::cout << mp3.first << " " << mp3.second << std::endl;
 
}