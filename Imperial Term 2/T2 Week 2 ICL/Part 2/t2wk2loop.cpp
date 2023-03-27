// Write a program which reads a number n from the user 
// then, using a loop, reads n integers from the user and builds a list containing them. Then print the list.

#include <iostream> 

struct IntListNode{
    int val; 
    IntListNode* next; 
}; 

void newnodefunc(int n) {

}

int main(){ 
    int n, x; 

    IntListNode* l; 
    l = NULL; 

    std::cout << "Please enter the number of digits in the list." << std::endl; 
    std::cin >> n; 

    std::cout << "Please enter the digits in the list. \n"; 

    IntListNode* tmp; 

    for(int i = 0; i < n; i++){
        std::cin >> x; 
        tmp = new IntListNode; 
        tmp->val = x; 
        tmp->next = l; 
        l = tmp; 
    }

    std::cout << "The list stored is: " << std::endl; 

    IntListNode* lit;
    lit = l;
 
    while(lit != NULL){
        std::cout << lit->val << std::endl;
        lit = lit->next;
    }
 
    lit = l;
 
    while(lit != NULL){
        tmp = lit->next;
        delete lit;
        lit = tmp;
    }
}