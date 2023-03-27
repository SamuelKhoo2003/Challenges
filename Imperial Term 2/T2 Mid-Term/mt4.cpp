#include <iostream>
typedef int list_t;
struct ListNode{
list_t val;
ListNode* next;
}; 

void deallocate_list(ListNode* l){
ListNode* tmp;
while(l != NULL){
tmp = l->next;
delete l;
l= tmp;
}
}
int main(){
ListNode* l;
ListNode* l2;
l2 = new ListNode;
l=l2;
l->val = 2;
ListNode* l3;
l3=l;
l2 = new ListNode;
l->next = l2;
l2->val = 3;
l3 = l2;
l3->next = NULL;

std::cout << l2 << std::endl; 
// what code should be here in order to print the memory address of the node containing 2?
deallocate_list(l);
}