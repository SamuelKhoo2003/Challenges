// Write a function int length_list(ListNode* l) which returns the length of a list passed in input (i.e. the number of nodes).
// Note that this is not influenced by the type of the values contained in the list nodes.

// Write a main to test the function using a list containing values of type int.

// Then write another version of the program using a list containing values of type std::string.
// for the string it is mostly the same, just converting the int to std::string for most of the code involving list_t

// I'm going to use the textfile and integerfile code as the base code and develop from there. 

#include <iostream>
#include <fstream> 
#include <vector> 
#include <string> 

typedef int list_t;
 
struct ListNode{
    list_t val;
    ListNode* next;
};
 
ListNode* cons_list(list_t e, ListNode* l){
    ListNode* tmp;
 
    tmp = new ListNode;
 
    tmp->val = e;
    tmp->next = l;
 
    return tmp;
}
 
void print_list(ListNode* l){
    while(l != NULL){
        std::cout << l->val << std::endl;
        l = l->next;
    }
}
 
void deallocate_list(ListNode* l){
    ListNode* tmp;
 
    while(l != NULL){
        tmp = l->next;
        delete l;
        l = tmp;
    }
}

int length_list(ListNode* l){
    int counter = 0; 
    while(l != NULL){
        l = l->next; 
        counter++; 
    }
    return counter; 
}
 
int main(){
    std::vector<int> elements; 
    std::ifstream input_list; 
    int tmp; 

    input_list.open("elementlist1.txt"); 
    
    if((!input_list.is_open())){
        std::cout << "error opening one of the input files." << std::endl; 
        return EXIT_FAILURE; 
    }

    while (input_list >> tmp){
        elements.push_back(tmp); 
    }

    input_list.close(); 

    ListNode* l = NULL;

    for(int i = 0; i < elements.size(); i++){
        l = cons_list(elements[i], l); 
    }

    std::cout << "The elements in the list are:" << std::endl; 
    
    print_list(l); 

    std::cout << "The length of the list is:" << std::endl; 

    std::cout << length_list(l) << std::endl; 
    // we dont need to reset the list to the top or have another variation of the list as the list is only run/read through within their respective functions. 

    deallocate_list(l); 



}