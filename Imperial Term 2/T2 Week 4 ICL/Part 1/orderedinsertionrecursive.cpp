// Consider the following function which performs the ordered insertion of an element in an ordered list (the empty list is an ordered list):
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

// Write a main to test the function.

int main(){
    int numdigit, input;
    ListNode* l = NULL; 

    std::cout << "Please enter how many digits you would like within your list. " << std::endl; 
    std::cin >> numdigit; 

    for(int i = 0; i < numdigit; i++){
        std::cout << "enter one of your digits: " << std::endl; 
        std::cin >> input; 
        l = ordered_insertion_list(input, l); 
        std::cout << "your list is now: " << std::endl; 
        print_list_rec(l); 
    }

    std::cout << "List is now complete. " << std::endl; 
    
}