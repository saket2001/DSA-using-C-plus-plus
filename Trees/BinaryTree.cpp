// Online C++ compiler to run C++ program online
#include <iostream>

struct BinaryTree{
    int data;
    BinaryTree* left;
    BinaryTree* right;
    
    BinaryTree(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

void preorder(struct BinaryTree *node){
    if(node==NULL){
        return;
    }
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
};

void inorder(struct BinaryTree *node){
    if(node==NULL){
        return;
    }
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
};

void postorder(struct BinaryTree *node){
    if(node==NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
};

int main() {
    //             1
    //      2            3 
    // 4        5   6          7


    // Write C++ code here
    struct BinaryTree *root = new BinaryTree(1);
    struct BinaryTree *n1 = new BinaryTree(2);
    struct BinaryTree *n2 = new BinaryTree(3);
    struct BinaryTree *n3 = new BinaryTree(4);
    struct BinaryTree *n4 = new BinaryTree(5);
    struct BinaryTree *n5 = new BinaryTree(6);
    struct BinaryTree *n6 = new BinaryTree(7);
     
    root->left=n1;
    root->right=n2;
    
    n1->left=n3;
    n1->right = n4;
    n2->left=n5;
    n2->right=n6;
    preorder(root);
    // inorder(root);
    // postorder(root);
    return 0;
}