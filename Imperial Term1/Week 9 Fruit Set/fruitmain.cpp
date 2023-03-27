#include <iostream> 
#include <vector> 
#include <cstdlib>
#include <string> 
#include <fstream> 

int search_vector(std::string s, const std::vector<std::string>& vin){
    // this approach solves it by checking each individual word alongside the code present
    // it isnt the most efficient way to solve it (this can be something to explore)

    for(int q = 0; q < vin.size(); q++){
        if(vin[q] == s)
        // we check each value of the vin with the word inputted at the string
        return 1; 
    }

    // the function returns 1 if identical words are found

    return 0;

    // the function returns 0 if no indentical words are found
}

void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){

    for(int k = 0; k < vin1.size(); k++){
        vout.push_back(vin1[k]);
    }
    // since this is a union, we first input all the words of the first vector as they are guaranteed to appear once

    for(int l = 0; l < vin2.size(); l++){
        if(search_vector(vin2[l], vin1) == 0){
            // using the search vector function, if it outputs 0 then it means that the words are indentical
            // we then choose to add these non-identical words into the vout vector
            vout.push_back(vin2[l]); 
        }
    }
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    
    for(int i = 0; i < vin1.size(); i++){
        // note the vin1[i] used within a for loop as we are checking each element of the vin1 vector alongside the entire vin2 list
        if(search_vector(vin1[i], vin2) == 1){
            // similar to the if statement in the union function, but outputting 1 instead as we are looking for shared products
            // we then add these shared products to the vout vecto
            vout.push_back(vin1[i]);
        }
    }
}


int main(){
    std::vector<std::string> vin1, vin2, vunion, vintrsct; 

    std::ifstream infile1; 
    infile1.open("warehouse1.txt");

    std::ifstream infile2; 
    infile2.open("warehouse2.txt");
    
    if((!infile1.is_open()) or (!infile2.is_open())) {
        std::cout << "error opening one of the input files" << std::endl; 
        return EXIT_FAILURE; 
    }
    // the if function above will print an error message if we fail to open either of the text files

    std::string tmp1, tmp2; 

    while (infile1 >> tmp1){
        vin1.push_back(tmp1); 
    }

    infile1.close();

    while (infile2 >> tmp2){
        vin2.push_back(tmp2); 
    }

    infile2.close(); 

    // this concludes the writing of the 2 input text files into vectors
    // we then run the functions previously created to retrieve the union and intersection values

    union_vector(vin1, vin2, vunion);
    intersection_vector(vin1, vin2, vintrsct); 
    
    std::ofstream outfile1; 
    outfile1.open("union.txt");

    for(int i = 0; i < vunion.size(); i++){
        outfile1 << vunion[i] << std::endl; 
    }

    outfile1.close(); 

    std::ofstream outfile2; 
    outfile2.open("intersection.txt");

    for(int j = 0; j < vintrsct.size(); j++){
        outfile2 << vintrsct[j] << std::endl; 
    }

    outfile2.close(); 

    // above we are printing and storing the vector string values into output text files that can be read

}