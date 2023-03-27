#include <iostream> 

int main(){ 
  int n, num, lower, upper;
  std::string i, j; 
  std::cout << "What please give a range where your number lies." << std::endl; 
  std::cin >> lower >> upper; 
  n = (upper+lower)/2;

  std::cout << "Is your number: " << n << std::endl; 
  std::cin >> j; 

  while(j != "y"){
    std::cout << "Is it higher?" << std::endl; 
  std::cin >> i; 
    if(i == "y"){ 
    n = (n+upper)/2;
      std::cout << "Is your number: " << n << std::endl; 
    std::cin >> j; 
    }
    else{ 
      num = (lower+n)/2; 
      if(num >= 0){
        n = n - num; 
        }
      else{
        n = n + num; 
      }
      std::cout << "Is your number: " << n << std::endl; 
      std::cin >> j; 
      }
    }
  std::cout << "Your number is: " << n << std::endl;
  
  }