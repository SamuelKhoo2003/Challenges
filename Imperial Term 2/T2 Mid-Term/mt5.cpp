#include <iostream>
typedef int list_t;
struct ListNode{
list_t val;
ListNode* next;
};

ListNode* f(list_t e, ListNode* l){
ListNode* tmp;
tmp = new ListNode;
tmp->val = e;
tmp->next = l;
return tmp;
}
ListNode* g(ListNode* l){
ListNode* l2;
l2 = NULL;
while(l != NULL){
l2 = f(l->val, l2);
l = l->next;
}
return l2;
}
void deallocate_list(ListNode* l){
ListNode* tmp;
while(l != NULL) {
tmp = l->next;
delete l;
l= tmp;
}
}
int main(){
ListNode* l;
l= NULL; 
ListNode* l2;
l2 = NULL;
for(int i = 3; i < 10; i++){
if((i % 2) == 0){
l2= f(i, l2);
}
}
l=g(l2);

std::cout << (l->next)->val << std::endl; 
//what code should be here in order to print the memory address of the node containing 47
deallocate_list(l);
deallocate_list(l2);
}