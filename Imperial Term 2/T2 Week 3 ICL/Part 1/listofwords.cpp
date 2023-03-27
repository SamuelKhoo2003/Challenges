#include <iostream>
#include <fstream> 
#include <vector> 
#include <string> 
// Similar to the Text file exercise above, but the text file contains words and the program builds a list whose nodes contain values of type std::string instead of int.

typedef std::string list_t;
// we need to change the typedef to string as we are now working with words instead of integers

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
    std::vector<std::string> words; 
    std::ifstream input_list; 
    std::string tmp; 

    input_list.open("textlist1.txt"); 
    
    if((!input_list.is_open())){
        std::cout << "error opening one of the input files." << std::endl; 
        return EXIT_FAILURE; 
    }

    while (input_list >> tmp){
        words.push_back(tmp); 
    }

    input_list.close(); 

    ListNode* l = NULL;

    for(int i = 0; i < words.size(); i++){
        l = cons_list(words[i], l); 
    }
 
    print_list(l);
 
    deallocate_list(l);
}
