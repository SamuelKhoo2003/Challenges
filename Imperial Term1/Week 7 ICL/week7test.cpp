#include <iostream>
bool f(int a, int b){
    bool out = false;
    if(a > b){
        if((a % b) == 1){
            out = false;
        }
        else{
            out = true;
        }
    }
    else{
        out = false;
    }
 
    return out;
 
}
 
int main(){
    int n = 6;
    for(int i = 1; i < 6; i++){
        if(f(n, i)){
            n = n - 2;
        }
        else{
            n = n + 2;
        }
    }
    std::cout << n << std::endl;
}
