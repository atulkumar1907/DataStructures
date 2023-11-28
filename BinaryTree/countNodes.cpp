#include<iostream>
#include<queue>
#include "node.hpp"

using namespace std;

int countAllNodes(node* root){

    if(root==NULL){
        return 0;
    }

    return countAllNodes(root->left) + countAllNodes(root->right) + 1;
}

int sumOfNodes(node* root){
    if(root==NULL){
        return 0;
    }

    return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<countAllNodes(root)<<endl;
    cout<<sumOfNodes(root)<<endl;
}