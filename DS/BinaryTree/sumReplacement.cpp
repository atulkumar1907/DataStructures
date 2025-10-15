#include<iostream>
#include<queue>
#include "node.hpp"

using namespace std;

void sumReplacement(node* root){
    if(root==NULL){
        return;
    }

    sumReplacement(root->left);
    sumReplacement(root->right);

    if(root->left){
        root->data += root->left->data;
    }
    if(root->right){
        root->data += root->right->data;
    }
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    preorder(root);
    cout<<endl;
    sumReplacement(root);
    preorder(root);
    cout<<endl;

}