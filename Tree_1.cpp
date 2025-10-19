#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node* right;
    Node(int val){
        data=val;
        right=left=nullptr;
    };
};

void PreOrder(Node *root){
    if(root != nullptr){
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}  

void InOrder(Node *root){
    if(root != nullptr){
        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }
}  

void PostOrder(Node *root){
    if(root != nullptr){
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }
}  

int main(){
    Node *root= new Node(10);
    root->left = new Node(11);
    root->right = new Node(22);
    root->left->left = new Node(41);
    root->left->right = new Node(45);
    
    cout<<"PreOrder traversal: "<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"InOrder traversal: "<<endl;
    InOrder(root);
    cout<<endl;
    cout<<"PostOrder traversal: "<<endl;
    PostOrder(root);

}