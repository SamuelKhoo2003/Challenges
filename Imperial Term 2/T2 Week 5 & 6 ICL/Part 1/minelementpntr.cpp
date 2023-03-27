//We consider ordered binary trees as previously defined, in which the left subtree contains elements that are less than the node pointing to it
// the right subtree contains elements that are greater than (or equal to) the node pointing to it.
//The program should read the elements to store in the tree from a text file.

//Write a function TreeNode* min_element_tree(TreeNode* t) that returns a pointer to the minimum element in t (NULL if t is empty). 
//Write a main to test the function which prints the value of the minimum element if the tree is not empty and “the tree is empty” otherwise.

//I will be working on this, using the old code from the previous week 

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
 
int main(){
    std::vector<int> elements; 
    std::ifstream input_tree; 
    int tmp; 

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

    if(min_element_tree(t) != NULL){
        std::cout << "The minimum value is: " << std::endl; 
        std::cout << min_element_tree(t)->val << std::endl; 
    }

    else{
        std::cout << "The tree is empty. " << std::endl; 
    }
    deallocate_tree(t);
 
}