#include<iostream>
#include "node.hpp"

using namespace std;

//case 1
void printSubtreeNodes(node* root, int k){
    if(root==NULL || k<0){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printSubtreeNodes(root->left, k-1);
    printSubtreeNodes(root->right, k-1);
}

// case 2
int nodesAtK(node* root, node* target,  int k){
    if(root==NULL){
        return -1;
    }

    if(root==target){
        printSubtreeNodes(root, k);
        return 0;
    }

    int dl = nodesAtK(root->left, target,  k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->right, k-dl-2);
        }
        return 1+dl;
    }
    int dr = nodesAtK(root->right,target,  k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->right, k-dr-2);
        }
        return 1+dr;
    }
}

int main(){
    return 0;
}