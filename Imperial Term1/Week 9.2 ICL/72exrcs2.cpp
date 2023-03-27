#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string> 
 
int main(){
 
    std::string inputfilename;
    // as usual not a special name
    std::cout << "enter name of input file" << std::endl;
 
    std::cin >> inputfilename;
    // note: for this to work the name of the file has to be written with a .txt at the end
    // the code below is the same as tthe previous exercise

    std::ifstream infile; 
    infile.open(inputfilename);

    std::vector<int> v;

    if (!infile.is_open()) {
        std::cout << "error opening the input file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while (infile >> tmp) {
        v.push_back(tmp);
    }

    infile.close(); 

    std::ofstream outfile;
    outfile.open("output2.txt");
    
    for(int i = (v.size() - 1); i >= 0; i--) {
        outfile << v[i] << std::endl; 
    }

    outfile.close();

}