//Using the function above, write a function (iterative, not recursive) ListNode* ordered_copy_list(ListNode* l) 
//which returns a copy of l which is ordered (the input l can be in any order, of course).
//Write a main to test the function.

// my plan for this is to write another function which uses the existing function from the last section within its own function. 

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
 

ListNode* ordered_insertion_list(list_t e, ListNode* l){
    if(l == NULL){
        return cons_list(e, l);
    }
    else if(e < l->val){
        return cons_list(e, l);
    }
    else{
        l->next=ordered_insertion_list(e, l->next);
        return l;
    }
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

ListNode* ordered_copy_list(ListNode* l){
    ListNode* ordered = NULL;

    while( l != NULL){
        ordered = ordered_insertion_list(l->val, ordered);
        l = l->next;
    }
    
    return ordered; 

}

// Write a main to test the function.

int main(){
    int numdigit, input;
    ListNode* l = NULL; 

    l = cons_list(5, l);
    l = cons_list(3, l);
    l = cons_list(4, l); 
    l = cons_list(6, l); 
    l = cons_list(8, l); 

    std::cout << "The original list is: " << std::endl; 
    print_list_rec(l);

    std::cout << "The new ordered list is: " << std::endl; 
    print_list_rec(ordered_copy_list(l)); 

    deallocate_list_rec(l); 
}