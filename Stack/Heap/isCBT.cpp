#include<iostream>
#include "./BinaryTree/node.hpp"
using namespace std;

int countNode(node* root){
    if(root==NULL) return 0;

    return countNode(root->left) + countNode(root->right) + 1;
}

bool isCBT(node* root, int i, int nodeCount){
    if(root==NULL) return true;

    if(i>=nodeCount) return false;

    return isCBT(root->left, 2*i+1, nodeCount) && isCBT(root->right, 2*i+2, nodeCount);
}

bool isMaxOrder(node* root ){
    if(root->left==NULL && root->right==NULL) return true;

    if(root->right==NULL){
        return root->data>root->left->data;
    }

    else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return (left && right &&(root->data>root->left->data && root->data>root->right->data));
    }

    return false;
}

bool isHeap(node* root){
    int index =0;

    int totalCount = countNode(root);
    if(isCBT(root, index, totalCount)&& isMaxOrder(root)){
        return true;
    }

    return false;
}


int main(){


    return 0;
}