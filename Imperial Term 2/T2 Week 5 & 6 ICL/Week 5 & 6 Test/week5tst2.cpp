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
        //return cons_tree(e, NULL, NULL);
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

    t = ordered_insertion_tree(2, t);
    t = ordered_insertion_tree(7, t);
    t = ordered_insertion_tree(5, t);
    t = ordered_insertion_tree(10, t);

    //std::cout << *(t->left) << std::endl;

    deallocate_tree(t);

}
// the code above will actually provide a compiler error as it isn't possible to print *(t->left)

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
        //return cons_tree(e, NULL, NULL);
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

    t = ordered_insertion_tree(5, t);
    t = ordered_insertion_tree(10, t);
    t = ordered_insertion_tree(7, t);
    t = ordered_insertion_tree(2, t);

   // what code should be here in order to print the memory address of the node containing 7?

    deallocate_tree(t);

}

// to print the address of the node containing 7 we would need  std::cout << (t->right)->left << std::endl;

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
        //return cons_tree(e, NULL, NULL);
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

    t = ordered_insertion_tree(2, t);
    t = ordered_insertion_tree(7, t);
    t = ordered_insertion_tree(5, t);
    t = ordered_insertion_tree(10, t);


   // what code should be here in order to print the memory address of the node containing 5?

    deallocate_tree(t);

}
// std::cout << (t->right)->left << std::endl; 


// NOTE: 
// the inserted of trees is different from how it works for list
// lists goes from last code written to first
// while tree goes from first to last


