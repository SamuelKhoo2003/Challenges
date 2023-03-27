#include <iostream>

int main(){
    int* p;
    p = new int;
    *p = 2;
    delete p;
    std::cout << p << std::endl;
}
// this will print the random address which p holds, cause even though it has been deallocated
// this is because the deallocation is only to remove the value 2 from p

#include <iostream>

struct IntListNode{
    int val;
    IntListNode* next;
};

int main(){
    IntListNode* l;

    IntListNode* tmp;

    tmp = new IntListNode;
    tmp->val = 2;
    tmp->next = l;

    l = tmp;

    tmp = new IntListNode;
    tmp->val = 3;
    tmp->next = l;

    l = tmp;

    IntListNode* lit;
    lit = l;

    while(lit != NULL){
        std::cout << lit->val << std::endl;
        lit = lit->next;
    }

    lit = l;

    while(lit != NULL){
        tmp = lit->next;
        delete lit;
        lit = tmp;
    }
}

// this code contains an undefined error/behaviour as it hasn't been set to NULL as it's initial value, hence it will get stuck in an infinite loop at printing

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
    ListNode* l = NULL;

    cons_list(2, l);
    cons_list(3, l);

    print_list(l);
    print_list(l);

    deallocate_list(l);
}
// the code above doesn't print anything as we need to set l = cons_list for the function to actually add anything to the list l we have assigned
// since we haven't done this, the code completes the writing of new value, but without a place to put the new value to