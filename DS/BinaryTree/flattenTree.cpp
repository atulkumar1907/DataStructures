#include<iostream>
#include "node.hpp"

using namespace std;

void flattenTree(node* root){

    if(root==NULL || root->left==NULL || root->right==NULL){
        return;
    }

    if(root->left!=NULL){
        flattenTree(root->left);

        node* rightTail = root->right;
        root->right = root->left;
        root->left = NULL;

        node* leftTail = root->right;

        while(leftTail->right!=NULL){
            leftTail=leftTail->right;
        }
        leftTail->right = rightTail;
    }

    flattenTree(root->right);
}


int main(){

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    
    return 0;
}