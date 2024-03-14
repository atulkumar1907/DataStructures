


#include<iostream>
#include<climits>
#include"node.hpp"
using namespace std;

int maxPathSumUtil(node* root, int &ans){
    if(root==NULL){
        return 0;
    }
    
    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    return singlePathSum;
}

int maxPathSum(node* root){

    int ans = INT_MIN;
    
    maxPathSumUtil(root, ans);

    return ans;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);

    cout<<"\nMaximum Path Sum: "
    <<maxPathSum(root)<<"\n";
}