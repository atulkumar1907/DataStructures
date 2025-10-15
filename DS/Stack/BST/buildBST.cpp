#include<iostream>
#include<climits>
#include "./bst.hpp"

using namespace std;

node* constructBST(int preorder[], int* preorderIdx, int key, int min, int max, int n){
    if(*preorderIdx>=n){
        return NULL;
    }

    node* root = NULL;
    if(key>min && key<max){
        root = new node(key);
        *preorderIdx += 1;

        if(*preorderIdx < n){
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if(*preorderIdx < n){
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }


    return root;

}

bool checkBST(node* root, node* min=NULL, node* max=NULL){

    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->data <= min->data){
        return false;
    }
    if(max!=NULL && root->data >= max->data){
        return false;
    }

    bool leftValid = checkBST(root->left, min, root);
    bool righttValid = checkBST(root->right, root, max);

    return (leftValid && righttValid);
}

node* balancedBST(int arr[], int st, int en){
    if(st>en){
        return NULL;
    }

    int mid = (st + en)/2;
    node* root = new node(arr[mid]);

    root->left = balancedBST(arr, st, mid-1);
    root->right = balancedBST(arr, mid+1, en);

    return root;

}

int main(){

    int preorder[] = {10, 2, 1, 13, 11};
    int n= 5;
    int preorderIdx = 0;
    node* root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    inorder(root); cout<<endl;

    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);

    if(checkBST(root1, NULL, NULL)){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }

    int arr[] = {10, 20, 30, 40, 50};
    node* root3 = balancedBST(arr, 0, 4);
    inorder(root3);

    return 0;
}