//Write a function bool replace_list(list_t e, list_t n, ListNode* l, bool all) which replaces occurrences of e in l with n and returns true if any replacements have taken place and false otherwise.
//Note that this is not influenced by the type of values contained in the list nodes as long as it's something on which the == operator and the = operator can be used.
//The function should replace all the occurrences of the value if the argument to parameter all is true and only the first occurrence if it is false. 
//You may find it convenient to write two more functions to call from this function, one which performs the replacement for all the occurrences and one that does it only for the first one.
//Write a main to test the function (test both the possible settings for parameter all) using a list containing values of type int.

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

bool replace_list(list_t e, list_t n, ListNode* l, bool all){
    bool change = 0; 
    if(all == 1){
        while(l != NULL){
            if(l->val == e){
                l->val = n; 
                change = 1; 
            }
            l = l->next; 
        }
        return change; 
    }

    else{
        while(l != NULL){
            if(l->val == e){
                l->val = n; 
                change = 1; 
                return change; 
            }
            l = l->next; 
        }
    }

    return change; 
}
 
int main(){
    std::vector<int> elements; 
    std::ifstream input_list; 
    std::string change_input; 
    int tmp, oldnum, newnum; 
    bool all; 

    input_list.open("replacetestlist.txt"); 
    
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

    std::cout << "Enter if you want to change all or one value: " << std::endl; 
    std::cin >> change_input; 

    if(change_input == "all"){
        all = true; 
    }

    else{
        all = false; 
    }

    std::cout << "Please enter the value you want to change, followed by the new value. " << std::endl; 
    std::cin >> oldnum >> newnum; 

    if(replace_list(oldnum, newnum, l, all) == 1){
            std::cout << "The new list is: " << std::endl; 
            print_list(l); 
    }

    else{
        std::cout << "No changes made to the list as the number requested isn't present. " << std::endl; 
    }


}

