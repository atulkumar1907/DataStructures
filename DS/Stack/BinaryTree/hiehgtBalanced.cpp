#include<iostream>
#include<queue>
#include "node.hpp"

using namespace std;

int height(node* root){
    if(root==NULL){
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

bool isbalanced(node* root){

    if(root==NULL){
        return true;
    }

    if(isbalanced(root->left)==false){
        return false;
    }
    if(isbalanced(root->right)==false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}
bool isBalanced(node* root, int* ht){

    if(root==NULL){
        return true;
    }
    int lh=0, rh=0;

    if(isBalanced(root->left, &lh)==false){
        return false;
    }
    if(isBalanced(root->right, &rh)==false){
        return false;
    }
    *ht = max(lh, rh)+1;

    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int ht=0;
    cout<<isbalanced(root)<<endl;
    cout<<isBalanced(root, &ht)<<endl;
    cout<<height<<endl;
}