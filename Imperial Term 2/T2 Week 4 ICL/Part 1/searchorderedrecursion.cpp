//Write a recursive function bool search_ordered_list_rec(list_t e, ListNode* l) which returns true if e is found in l and false otherwise.
//As in the iterative version, this function should be optimised to work on lists that are in ascending (or non-descending) order. 
//This means that for example if l contains 2, 7, 10, 15 and e is 6, then the search should stop as soon as 7 is encountered.

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

bool search_ordered_list_rec(list_t e, ListNode* l){
    if(l->val > e){
        return false; 
    }
    if(l->val == e){
        return true;
    }
    else{
        return search_ordered_list_rec(e, l->next); 
    }
    
}
 
int main(){
    ListNode* l = NULL;
 
    l = cons_list(99, l);
    l = cons_list(62, l);
    l = cons_list(70, l); 
    l = cons_list(60, l); 
    
    print_list_rec(l);

    std::cout << search_ordered_list_rec(62, l) << std::endl; 

    deallocate_list_rec(l);
}