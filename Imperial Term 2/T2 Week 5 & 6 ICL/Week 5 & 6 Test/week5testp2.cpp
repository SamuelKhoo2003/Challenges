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

    t = ordered_insertion_tree(5, t); // this is inserted first
    t = ordered_insertion_tree(10, t);
    t = ordered_insertion_tree(7, t);
    t = ordered_insertion_tree(2, t); // this is inserted last

    // the structure of this is 
                //5
        //2       //10
                //7      //null
            //nul     //null


// think of the tree as being constructed with the next 2 values being inserted or any remaining past values that haven't been used




    std::cout << (t->left)->val << std::endl; 
   // what code should be here in order to print the memory address of the node containing 7?

    deallocate_tree(t);

}