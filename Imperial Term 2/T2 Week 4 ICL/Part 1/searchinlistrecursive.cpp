//Write a recursive function bool search_list_rec(list_t e, ListNode* l) which returns true if e is found in l and false otherwise.
//Consider the following recursive notation:

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

bool search_list_rec(list_t e, ListNode* l){
    if(l == NULL){
        return false; 
    }
    if(l->val == e){
        return true;
    }
    else{
        return search_list_rec(e,l->next);
    }
}
 
int main(){
    ListNode* l = NULL;
 
    l = cons_list(99, l);
    l = cons_list(10, l);
    l = cons_list(67, l); 
    l = cons_list(52, l); 
    
    print_list_rec(l);

    std::cout << search_list_rec(67,l) << std::endl;

    deallocate_list_rec(l);
}