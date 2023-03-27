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

    t = ordered_insertion_tree(2, t); //inserted first
    t = ordered_insertion_tree(7, t);
    t = ordered_insertion_tree(5, t);
    t = ordered_insertion_tree(10, t);//inserted last

    // 2
    // l = null // r = 7
    // rl = 5 // rr = 10

    std::cout << t->val << std::endl; 

   // what code should be here in order to print the memory address of the node containing 5?

    deallocate_tree(t);

}
