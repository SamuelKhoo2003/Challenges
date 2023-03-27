// extend upon the old program to include all (if any) of the indices where the number the user is looking for is found. 

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
    std::vector<int> indices; 

    std::cout << "Please enter the number you are looking for. " << std::endl; 
    std::cin >> s; 
    for(int j = 0; j < store.size(); j++){
        if(store[j] == s){
            counter++; 
            indices.push_back(j); 
        }
    }
    std::cout << "There are " << counter << " occurrences of the number " << s << " at indices: " << std::endl; 
    for (int k : indices){
        std::cout << k << " "; 
    }
}