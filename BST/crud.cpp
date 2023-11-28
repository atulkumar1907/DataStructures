#include<iostream>
#include "./bst.hpp"

using namespace std;

node* searchInBST(node* root, int key){
    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        return root;
    } else if(root->data>key){
        searchInBST(root->left, key);
    } else{
        searchInBST(root->right, key);
    }
}

node* inorderSucc(node* root){
    node* curr = root;
    while(curr && curr->left!=NULL) {
        curr = curr->left;
    }
    return curr;
}

node* deleteInBST(node* root, int key){

    if(root->data>key){
        root->left = deleteInBST(root->left, key);
    }
    else if(root->data<key){
        root->right= deleteInBST(root->right, key);
    }
    else{
        if(root->left==NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

int main(){
    
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);
    int key = 6;

    if(searchInBST(root, key)==NULL){
        cout<<"Node doesm't exist"<<endl;
    }
    else{
        cout<<"Node exist"<<endl;
    }

    root = deleteInBST(root, 5);
    inorder(root);cout<<endl;
    

    return 0;
}