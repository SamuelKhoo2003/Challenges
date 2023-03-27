#include <iostream>
 
// Edit the program above so that it reads a number n from the user 
// Then using a loop, reads n integers from the user and builds a list containing them. 
//Then print the list.

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
    int n, m;  
    ListNode* l = NULL;

    std::cout << "Please enter the number of digits you want within the list." << std::endl; 
    std::cin >> n; 
    std::cout << "Please enter the digits you want to store within the list." << std::endl; 

    for(int i = 0; i < n; i++){
        std::cin >> m; 
        l = cons_list(m, l); 
    }

    std::cout << "The digits stored within the list is: " << std::endl; 
    
    print_list(l);
 
    deallocate_list(l);
}