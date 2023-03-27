#include <iostream>
#include <fstream> 
#include <vector>

// Edit the program above so that it reads the elements that are used to build the list from a text file. Then print the list.

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
 
    print_list(l);
 
    deallocate_list(l);
}