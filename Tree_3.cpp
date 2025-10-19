#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *left;
    Node *right;

    Node(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    };
};

class BST{
    public:
    Node *root = NULL;
    Node* create_BST(Node *root, int data){
        if(!root){
            root = new Node(data);
            return root;
        }
        if(root -> val > data){
            root->left = create_BST(root->left , data);
        }
        else if(root -> val < data){
            root -> right = create_BST(root->right , data);
        }

        return root;
    }

    void InorderTraversal(Node *root){
        if(root == NULL) return;
        InorderTraversal(root->left);
        cout<<root->val<<" ";
        InorderTraversal(root->right);
    }
};

int main(){
    BST tree;
    // vector <int> store(10);
    cout<<"Enter any 10 integer values: ";
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
        
    }for(int i=0;i<10;i++){
        tree.root = tree.create_BST(tree.root , arr[i]);
    }

    cout<<"Inorder Traversal: ";
    tree.InorderTraversal(tree.root);
}