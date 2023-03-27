#include <iostream>
 
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
 
void deallocate_list(ListNode* l){
    ListNode* tmp;
 
    while(l != NULL){
        tmp = l->next;
        delete l;
        l = tmp;
    }
}
 
int main(){
    ListNode* l;
    l = NULL;
 
    l = cons_list(2, l);
    l = cons_list(3, l);
 
    //std::cout << *l << std::endl;
   
    deallocate_list(l);
}
// this won't run as it is not possible to print a *l 

