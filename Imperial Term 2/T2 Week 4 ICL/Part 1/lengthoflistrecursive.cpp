//Write a recursive function int length_list_rec(ListNode* l) which returns the length of a list passed in input.
//In recursive terms we can say that the length of a list is 0 if the list is empty and 1 plus the length of the rest of the list otherwise.

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
 
 
 
void print_list_rec(ListNode* l){
    if(l != NULL){
        std::cout << l->val << std::endl;
        // we print the first element
        print_list_rec(l->next);
        // then the rest of the list
    }
}
 
void deallocate_list_rec(ListNode* l){
    ListNode* tmp;
 
    if(l != NULL){
        tmp = l->next;
        delete l;
        deallocate_list_rec(tmp);
    }
}

int length_list_rec(ListNode* l){
    if(l == NULL){
        return 0;
    }

    else{
        return 1 + length_list_rec(l->next);
    }
}
 
int main(){
    ListNode* l = NULL;
 
    l = cons_list(2, l);
    l = cons_list(3, l);
    l = cons_list(4, l); 
    l = cons_list(5, l); 
    
    print_list_rec(l);

    std::cout << length_list_rec(l) << std::endl; 

    deallocate_list_rec(l);
}