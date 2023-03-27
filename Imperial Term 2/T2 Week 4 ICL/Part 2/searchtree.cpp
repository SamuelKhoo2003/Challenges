//When we considered ordered lists we could optimise the search function by realising for example that if the list contains 2, 7, 10, 15 and we are looking for 6, 
//then the search should stop as soon as 7 is encountered.
//On ordered binary trees we can do better than that: when we visit a node (starting from the first one) 
//we know that all the elements with values less than the current node are in the left subtree and the other ones are in the right subtree, and we can keep doing this recursively.
//The more the tree is balanced, the closer we get to halving the search space at each node.
//In recursive notation this can be expressed as follows:

#include <iostream>
 
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

bool search_ordered_tree(tree_t e, TreeNode* t){
    if(t == NULL){
        return false; 
    }
    if(t->val == e){
        return true; 
    }
    if(t->val > e){
        return search_ordered_tree(e, t->left); 
    }
    else{
        return search_ordered_tree(e, t->right); 
    }
}

int main(){
    TreeNode* t;
    t = NULL;

    int input; 
 
    t = ordered_insertion_tree(15, t);
    t = ordered_insertion_tree(20, t);
    t = ordered_insertion_tree(6, t);
    t = ordered_insertion_tree(1, t);
    t = ordered_insertion_tree(4, t);
    t = ordered_insertion_tree(18, t);
    t = ordered_insertion_tree(9, t);

    std::cout << "The ordered tree is: " << std::endl; 
    print_tree(t);

    std::cout << "Please enter the value you are looking for: " << std::endl; 
    std::cin >> input; 

    if(search_ordered_tree(input, t) == true){
        std::cout << "The value is found within your tree. " << std::endl; 
    }

    else{
        std::cout << "The value is not found within your tree. " << std::endl; 
    }    
 
    deallocate_tree(t);
 
}
