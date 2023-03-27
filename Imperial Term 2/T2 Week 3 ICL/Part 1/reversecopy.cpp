//Write a function ListNode* reversed_copy_list(ListNode* l) which returns a copy of l which is in reverse order. Use cons_list within this function.
//Write a main to test the function using a list containing values of type int.
//Then write another version of the program using a list containing values of type std::string.

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

ListNode* reversed_copy_list(ListNode* l){
    ListNode* newlist = NULL; 
    while(l != NULL){
        newlist = cons_list(l->val, newlist); 
        l = l->next; 
    }
    return newlist; 
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

    std::cout << "The reversed list is:" << std::endl; 

    print_list(reversed_copy_list(l)); 
}

