#include<iostream>
usinf=g namespace std;

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

    void BST(Node *root, int data){
        if(!root){
            root = new Node(data);
            return;
        }
        
    }
};