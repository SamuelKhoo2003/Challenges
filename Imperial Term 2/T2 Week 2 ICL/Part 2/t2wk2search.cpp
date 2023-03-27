// Extend the program above so that after the list is printed the program reads another number in input from the user. 
// This number is then searched in the list and the program prints whether or not it is contained in the list.

#include <iostream> 

struct IntListNode{
    int val; 
    IntListNode* next; 
}; 

int main(){ 
    int n, x, y; 

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

    delete lit; 

    std::cout << "Please enter the number that you are searching for. " << std::endl; 
    std::cin >> y; 

    IntListNode* search; 
    search = l; 

    bool check = false; 

    while(search != NULL){ 
        if(y == search->val){
            std::cout << "the number is found within the list" << std::endl; 
            search = search->next; 
            check = true; 
        }
        else{
            search = search->next; 
        }
    
    }

    if(check == false){
        std::cout << "the number is not found within the list" << std::endl; 
    }

    search = l; 
    while(search != NULL){
        tmp = search->next;
        delete search;
        search = tmp;
    }
}