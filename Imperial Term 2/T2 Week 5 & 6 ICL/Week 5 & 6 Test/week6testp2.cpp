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
 
void deallocate_tree(TreeNode* t){
    if(t != NULL){
        deallocate_tree(t->left);
        deallocate_tree(t->right);
        delete t;
    }
}
 
int main(){
    TreeNode* t;
    t = NULL;
 
    tree_t n;
    std::cin >> n;
 
    t = ordered_insertion_tree(30, t);
    t = ordered_insertion_tree(10, t);
    t = ordered_insertion_tree(15, t);
    t = ordered_insertion_tree(45, t);
    t = ordered_insertion_tree(n, t);
    t = ordered_insertion_tree(70, t);
    t = ordered_insertion_tree(32, t);
    t = ordered_insertion_tree(44, t);
    t = ordered_insertion_tree(21, t);
 
    std::cout << ((t->right)->left)->right << std::endl;
 
    deallocate_tree(t);
 
}

// n is none of the options as if n was 25, the 32 would still fit in the left node of 70 over being inserted to the right node of 25