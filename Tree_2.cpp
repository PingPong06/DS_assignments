#include<iostream>
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
    bool is_present(Node* root, int target){
        if(root == NULL) return false;
        if(root->val == target) return true;
        if(is_present(root->left, target) ||is_present(root->right, target)) return true;
    }

};

int main(){
    Node *root = new Node(13);
    root->left = new Node(43);
    root->right = new Node(33);
    root->left->right = new Node(43);
    root->left->left = new Node(23);
    root->right->left = new Node(45);

    int target;
    cout<<"Enter the value you are searching for: ";
    cin>>target;

    if(root->is_present(root, target) == 1) cout<<"Present"<<endl;
    else cout<<"Not Present"<<endl;
    return 0;
}