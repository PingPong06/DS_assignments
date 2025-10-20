#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left ;
    Node* right ;

    Node(int data){
        left = NULL;
        right = NULL;
        val=data;
    };
};

class BST{
    public:
    Node *root = NULL;

    Node *left_traverse_only(Node* traverser){
        while(traverser->left != NULL){
            traverser = traverser->left;
        }
        return traverser;
    }

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


    Node * deleteNode(Node *root, int key){
        if(!root) return root;

        if(key > root->val){
            root->right = deleteNode(root->right , key);
        }
        else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        
        else{
            if(root -> left == NULL && root -> right ==NULL){
                delete root;
                return NULL;
            }
            
            else if(root->left == NULL && root->right != NULL){
                Node *temp = root->right;
                delete root;
                return temp;
            }

            else if(root->left != NULL && root->right == NULL){
                Node *temp = root->left;
                delete root;
                return temp;
            }

            else{
                Node* temp = root->right;
                
                Node *leftNode=left_traverse_only(root);
                delete root;
                leftNode->right = temp;
                return leftNode;
            }
        }
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
    cout<<"Enter the number of elements to be inserted in the BST: ";
    int n;
    cin>>n;
    cout<<"Enter the elements you want to insert in your BST: ";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        tree.root = tree.create_BST(tree.root , arr[i]);
    }
    
    cout<<"The inorder traversal: "; 

    tree.InorderTraversal(tree.root);

    cout<<"\nEnter the element you want to delete from your BST: ";
    int to_be_deleted;
    cin>>to_be_deleted;

    tree.deleteNode(tree.root , to_be_deleted);

    cout<<"\nThe inorder traversal of the new BST looks like: ";
    tree.InorderTraversal(tree.root);

}