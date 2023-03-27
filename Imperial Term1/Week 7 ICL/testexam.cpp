#include <iostream>

bool f(int a, int b){

bool out;
if(a < b){
out = true;
}
else if(a == b){
out = false;
}
else {

if((a % b) == 1){
out = false;

}
else{

out = true;
}

}

return out;

}

int main(){
int n = 0;
for(int i = 0; i < 5; i++){
if(f(n, i)){

n=n+4;
}

else{

n=n- 1;
}
}
std::cout << n << std::endl;
}