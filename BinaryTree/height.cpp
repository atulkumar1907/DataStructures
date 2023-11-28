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

int diameter(node* root){
    if(root==NULL){
        return 0;
    }

    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);



    return max(currDiameter, max(lDiameter, rDiameter));
}

int calcdiameter(node* root, int* ht){
    if(root==NULL){
        return 0;
    }

    int lh = 0, rh=0;

    int lDiameter = calcdiameter(root->left, &lh);
    int rDiameter = calcdiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *ht = max(lh, rh)+ 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int  hight = 0;

    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;
    cout<<calcdiameter(root, &hight)<<endl;
}