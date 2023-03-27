//Write a function bool search_list(list_t e, ListNode* l) which returns true if e is found in l and false otherwise. 
//Note that this is not influenced by the type of values contained in the list nodes as long as it's something on which the == operator can be used.

//Then write another version of the program using a list containing values of type std::string.
//For the std:string it is relatively similar just for typedef std::string list_t


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

bool search_list(list_t e, ListNode* l){
    while(l != NULL){
        if(l->val == e){
            return 1; 
        }
        else{
            l = l->next; 
        }
    }
    return 0; 
}
 
int main(){
    std::vector<int> elements; 
    std::ifstream input_list; 
    int tmp, search; 

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

    std::cout << "Enter the value you are looking for:" << std::endl; 
    std::cin >> search; 

    if(search_list(search, l) == 1){
        std::cout << "The value is found within the list. " << std::endl; 
    }

    else{
        std::cout << "The value is not found within the list. " << std::endl; 
    }

}

