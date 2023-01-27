#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *insertBST(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
};

Node *searchInBST(Node *root, int key)
{
    if (root == nullptr)
        return NULL;
    if (root->data == key)
        return root;
    if (root->data > key)
        return searchInBST(root->left, key);
    // data < key
    return searchInBST(root->right, key);
}

Node *inorderSucc(Node *root) {
    Node *curr = root;
    while(curr && curr->left !=nullptr){
        curr = curr->left;
    }
    return curr;
}

Node *deleteInBST(Node *root, int key)
{
    // searching
    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    // delete operations
    else
    {
        // case 1 & 2
        if (root->right == nullptr)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == nullptr)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        // case 3
        else
        {
            // 1. find inorder successor
            Node *temp = inorderSucc(root->right);
            // 2. swap them
            root->data = temp->data;
            // 3. delete node
            free(temp);
        }
    }
    return root;
}

int main()
{
    /*
                10
            5       12
        2       7
    */
    Node *root = nullptr;
    root = insertBST(root, 10);
    insertBST(root, 5);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 12);
    insertBST(root, 20);

    // inorder(root);

    // if (searchInBST(root, 212))
    //     cout << "Key exists in tree" << endl;
    // else
    //     cout << "Key doesn't exists in tree" << endl;

    inorder(root);
    cout << "before delete" << endl;
    root = deleteInBST(root, 5);
    inorder(root);
    cout << "after delete" << endl;


    return 0;
}
