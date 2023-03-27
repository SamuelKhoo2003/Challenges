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
int f(ListNode* l){
if(l == NULL){
return 0;
}
else if(l->next == NULL){
return 1;
}
else{
return l->val + f(l->next);
}
}
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
l = NULL;
int n;
std::cin >> n;
for(int i = 2; i < n; i++){
l = cons_list(i, l);
}
std::cout << f(l) << std::endl;
deallocate_list(l);
}