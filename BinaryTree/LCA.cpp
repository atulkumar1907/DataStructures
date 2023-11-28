#include<iostream>
#include<vector>
#include"node.hpp"
using namespace std;

bool getPath(node* root, int n, vector<int> &path){

    if(root==NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    if(getPath(root->left, n, path)){
        return true;
    }
    if(getPath(root->right, n, path)){
        return true;
    }
    path.pop_back();
    return false;
}

int lowestCommonAncestor(node* root, int n1, int n2){
        if(root==NULL){
            return -1;
        }

        vector<int> path1, path2;

        if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
            return -1;
        }

        int pc;
        for(pc=0; pc<path1.size()&& pc<path2.size(); pc++){
            if(path1[pc]!=path2[pc]){
                break;
            }
        }
        return path1[pc-1];

}

node* LCA(node* root, int n1, int n2){
    if(root->data==n1 || root->data==n2){
        return root;
    }

    node* leftLCA = LCA(root->left, n1, n2);
    node* rightLCA = LCA(root->right, n1, n2);

    if(leftLCA && rightLCA){
        return root;
    }

    if(leftLCA!=NULL){
        return leftLCA;
    }

        return rightLCA;
    
}

int main(){

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // cout<<lowestCommonAncestor(root, 7, 6);

    node* lca = LCA(root, 6, 7);
    cout << lca->data;
    cout<<'j';
    return 0;
}