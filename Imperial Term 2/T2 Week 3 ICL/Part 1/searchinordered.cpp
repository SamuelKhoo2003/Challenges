//Write a function bool search_ordered_list(list_t e, ListNode* l) which returns true if e is found in l and false otherwise.
//This version of the function should be optimised to work on lists that are in ascending (or non-descending) order.
//This means that for example if l contains 2, 7, 10, 15 and e is 6, then the search should stop as soon as 7 is encountered.
//Note that this is not influenced by the type of values contained in the list nodes as long as it's something on which the == operator and the < operator can be used.
//We can use the < operator also on std::string (it behaves following the alphabetic order).

//I'm going to write this code based on the previous code and tasks which I have already worked on

#include <iostream>
#include <fstream> 
#include <vector> 
#include <string> 

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

int length_list(ListNode* l){
    int counter = 0; 
    while(l != NULL){
        l = l->next; 
        counter++; 
    }
    return counter; 
}

bool search_list(list_t e, ListNode* l){
    while(l != NULL){
        if(l->val == e){
            return 1; 
        }
        else{
            l = l->next; 
        }
    }
    return 0; 
}

bool search_ordered_list(list_t e, ListNode* l){
    while(l != NULL){
        if(l->val == e){
            return 1; 
        }
        else if(l->val != e)
        l = l->next; 
        if(l->val > e){
            return 0; 
        }
    }
    return 0; 
}
 
int main(){
    std::vector<int> elements; 
    std::ifstream input_list; 
    int tmp, search; 

    input_list.open("orderedlist1.txt"); 
    
    if((!input_list.is_open())){
        std::cout << "error opening one of the input files." << std::endl; 
        return EXIT_FAILURE; 
    }

    while (input_list >> tmp){
        elements.push_back(tmp); 
    }

    input_list.close(); 

    ListNode* l = NULL;

    for(int i = 0; i < elements.size(); i++){
        l = cons_list(elements[i], l); 
    }

    std::cout << "The elements in the list are:" << std::endl; 
    
    print_list(l); 

    std::cout << "Enter the value you are looking for in the ordered list:" << std::endl; 
    std::cin >> search; 

    if(search_ordered_list(search, l) == 1){
        std::cout << "value found" << std::endl; 
    }

    else{
        std::cout << "value not found" << std::endl; 
    }

}

