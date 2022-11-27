// write a code that can read the context of a text file and print it on another file in reverse order. 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int main()
{
    std::ifstream infile;
    infile.open("input1.txt");

    std::vector<int> v;

    if (!infile.is_open()) {
        std::cout << "error opening the input file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while (infile >> tmp) {
        v.push_back(tmp);
        // instead of printing the values
        // as in the example above
        // first we store them in a vector
    }

    infile.close();

    // TODO: print the content of v in reversed order
    // onto a different text file

    std::ofstream outfile;
    outfile.open("output1.txt");
    
    for(int i = (v.size() - 1); i >= 0; i--) {
        outfile << v[i] << std::endl; 
    }

    outfile.close();
    
}