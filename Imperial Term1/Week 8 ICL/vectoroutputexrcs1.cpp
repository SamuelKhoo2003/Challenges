#include <iostream>
#include <vector>
 
// this function uses a pass by reference for the vecotr vout (it takes/borrows the existing value and returns it changed)

void from_1_to_n(int n, std::vector<int>& vout){
 
    for(int i = 0; i < n; i++){
        vout.push_back(i+1);
    }
 
}
 
int main(){
    // this program will not work as expected...
    std::vector<int> v;
 
    for(int n = 3; n < 7; n++){
        from_1_to_n(n, v);
 
        std::cout << "printing vector:" << std::endl;
        for(int i = 0; i < v.size(); i++){
            std::cout << v[i] << std::endl;
        }
    }
}

// this doesnt work as expected as the vector isn't cleared/resetted after each run, hence this causes the vector still have the previous values from earlier
// I expect:
// print 1: 1 2 3
// print 2: 1 2 3 1 2 3 4
// so on and on ...