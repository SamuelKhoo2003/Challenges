//Write a function int replace_tree(tree_t e, tree_t r, TreeNode* t, int n) which attempts to replace n occurrences of e in t with r 
//and returns how many replacements have actually taken place .
//The number of replacements may be less than n, and possibly 0, depending on how many occurrences of e are in t.
//After the replacement(s) the tree may or may not still be a valid ordered tree, depending on the values involved.
//Do not call function int count_occurrences_tree(tree_t e, TreeNode* t) within this function.
//Write a main to test the function.

//I'm going to use the old code as a base code once again. 

#include <iostream>
#include <vector> 
#include <fstream> 
 
typedef int tree_t;
 
struct TreeNode{
    tree_t val;
    TreeNode* left;
    TreeNode* right;
};
 
TreeNode* cons_tree(tree_t e, TreeNode* l, TreeNode* r){
    TreeNode* tmp;
    tmp = new TreeNode;
    tmp->val = e;
    tmp->left = l;
    tmp->right = r;
    return tmp;
}
 
TreeNode* ordered_insertion_tree(tree_t e, TreeNode* t){
    if(t == NULL){
        return cons_tree(e, NULL, NULL);
    }
    else if(e < t->val){
        t->left = ordered_insertion_tree(e, t->left);
        return t;
    }
    else{
        t->right = ordered_insertion_tree(e, t->right);
        return t;
    }
}

TreeNode* min_element_tree(TreeNode* t){
    if(t == NULL){
        return NULL; 
    }
    if(t->left == NULL){
        return t;
    }
    else{
        return min_element_tree(t->left); 
    }
}
 
void print_tree(TreeNode* t){
    if(t != NULL){
        print_tree(t->left);
        std::cout << t->val << std::endl;
        print_tree(t->right);
    }
}
 
void deallocate_tree(TreeNode* t){
    if(t != NULL){
        deallocate_tree(t->left);
        deallocate_tree(t->right);
        delete t;
    }
}

int count_nodes_tree(TreeNode* t){
    if(t == NULL){
        return 0; 
    }
    else{
        return 1 + count_nodes_tree(t->left) + count_nodes_tree(t->right); 
    }
}

int count_leaves_tree(TreeNode* t){
    if(t == NULL){
        return 0; 
    }
    if(t->left == NULL && t->right == NULL){
        return 1; 
    }
    else{
        return count_leaves_tree(t->left) + count_leaves_tree(t->right); 
    }
}

int count_occurrences_tree(tree_t e, TreeNode* t){
    if(t == NULL){
        return 0; 
    }
    if(t->val == e){
        return 1 + count_occurrences_tree(e, t->right); 
    }
    else{
        return 0 + count_occurrences_tree(e, t->right) + count_occurrences_tree(e, t->left); 
    }
}
// since the left subtree always contains elements less than the value, we can skip it if t->val == e
 
int replace_tree(tree_t e, tree_t r, TreeNode* t, int n){
    if(n == 0 || t == NULL){
        return 0;
    }
    else{
        if(t->val == e){
            t->val = r; 
            return 1 + replace_tree(e, r, t->right, n-1); 
        }
        return 0 + replace_tree(e, r, t->left, n) + replace_tree(e, r, t->right, n); 
    }
}
// once again we can skip the left sub tree as if t->val == e, it can no longer be in the left subtree. 

int main(){
    std::vector<int> elements; 
    std::ifstream input_tree; 
    int tmp, oldval, newval, n; 

    input_tree.open("elementsfortree.txt"); 

    if((!input_tree.is_open())){
        std::cout << "error opening one of the input files. " << std::endl; 
        return EXIT_FAILURE; 
    }

    while (input_tree >> tmp){
        elements.push_back(tmp); 
    }

    input_tree.close(); 

    TreeNode* t;
    t = NULL;

    for(int i = 0; i < elements.size(); i++){
        t = ordered_insertion_tree(elements[i], t); 
    }
    print_tree(t); 

    std::cout << "Please enter value you want to replace within the tree: " << std::endl; 
    std::cin >> oldval; 

    std::cout << "Please enter the number of occurrences you want to replace: " << std::endl; 
    std::cin >> n; 

    std::cout << "Please enter the new value which you want within the tree: " << std::endl; 
    std::cin >> newval; 

    std::cout << "The number of replacements that have taken place is: " << std::endl; 
    std::cout << replace_tree(oldval, newval, t, n); 
 
    deallocate_tree(t);
 
}   