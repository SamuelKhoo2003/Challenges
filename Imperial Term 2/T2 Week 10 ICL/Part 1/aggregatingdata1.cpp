#include <iostream> 
#include <string> 
#include <utility> 
#include <vector> 
#include <fstream> 

std::vector<std::pair<std::string, int>> aggregate_pairs(const std::vector<std::pair<std::string, int>>& v){
    std::vector<std::pair<std::string, int>> results; 
    std::pair<std::string, int> tmp;
    results.push_back(v[0]); 
    int counter = 0; 
    for(int i = 1; i < v.size(); i++){
        tmp = v[i]; 
        if(tmp.first == results[counter].first){
            results[counter].second = tmp.second + results[counter].second;
        }
        else{
            counter++; 
            results.push_back(tmp); 
        }
    }
    return results; 
}


int main(){
    std::string input, output; 
    std::cout << "Please enter the name of the input file." << std::endl; 
    std::cin >> input; 

    std::vector<std::pair<std::string, int> > inputval, results; 
    std::ifstream infile; 
    infile.open(input); 

    if(!infile.is_open()){
        std::cout << "There has been an error opening the input file." << std::endl; 
        return EXIT_FAILURE; 
    }

    std::string tmps; 
    int tmpi; 
    while (infile >> tmps >> tmpi){
        inputval.emplace_back(tmps, tmpi); 
    }

    infile.close(); 

    results = aggregate_pairs(inputval); 

    std::cout << "Please enter the name of the output file." << std::endl; 
    std::cin >> output; 

    std::ofstream outfile; 
    outfile.open(output); 

    if(!outfile.is_open()){
        std::cout << "There has been an error opening the output file." << std::endl; 
        return EXIT_FAILURE; 
    }
    for(int j = 0; j < results.size(); j++){
        outfile << results[j].first << " " << results[j].second << std::endl; 
    }

    outfile.close(); 
}
