#include<iostream>
#include<climits>
#include "bst.hpp"

using namespace std;

struct info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largestBST(node* root){
    if(root==NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1, root->data, root->data, 1, true};
    }

    info left = largestBST(root->left);
    info right = largestBST(root->right);

    info curr;
    curr.size = (1+ left.size + right.size);

    if(left.isBST && right.isBST && left.max<root->data && right.min>root->data){
        curr.min = min(root->data, min(left.min, right.min));
        curr.max = max(root->data, max(left.max, right.max));
        curr.ans = curr.size;
        curr.isBST = true;
        return {curr.size, curr.min, curr.size, curr.ans, curr.isBST };
    }

    curr.ans = max(left.ans, right.ans);
    curr.isBST = false;

    return curr;


}

int main(){

    node* root= new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    cout<<largestBST(root).ans<<endl;

    return 0;
}

