#include<iostream>
#include<climits>
using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node*right;

    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    };

    static void InOrder(Node *root){
        if(root != nullptr){
            InOrder(root->left);
            cout<<root->val<<" ";
            InOrder(root->right);
        }
    }  

    static bool is_BST(Node *root , int mini , int maxi){
        if(!root) return true;
        
        if(root->val <= mini || root->val >= maxi) return false;
        return is_BST(root->left, mini, root->val) && is_BST(root->right, root->val, maxi);
    }
};

int main(){
    Node * root = new Node(45);
    root->left = new Node(42);
    root->right = new Node(50);
    root->left->left = new Node(39);
    root->left->right = new Node(44);
    root->right->left = new Node(48);

    cout<<"If the given Binary tree is BST or not?\n";

    cout<<"The inorder traversal of the given Binary Tree is: ";
    Node::InOrder(root);

    char guess;
    cout<<"\nWhat's your guess? (Y or N):\n";
    cin>>guess;
    if(Node::is_BST(root, INT_MIN, INT_MAX)){
        if(guess == 'Y')
            cout<<"YES! , you are right it is a BST";
        else
            cout<<"Nice try but it is a BST";
    }
    else{
        if(guess == 'N')
            cout<<"YES! , it is not a BST";
        else 
            cout<<"Nice try, but it is a BST";
    }
}
