#include<iostream>
#include<vector>
#include "bst.hpp"

using namespace std;

int catalan(int n){
    if(n==0 || n==1){
        return 1;
    }

    int res = 0;
    for(int i=0; i<n; i++){
        res += catalan(i) + catalan(n-i-1);
    }
    return res;
}

vector<node*> constructTree(int st, int en){
    vector<node*> trees;

    for(int i=st; i<=en; i++){
        vector<node*> leftSubtree = constructTree(st, i-1);
        vector<node*> rightSubtree = constructTree(i+1, en);

        for(int j=0; j<leftSubtree.size(); j++){
            node* left = leftSubtree[j];
            for(int k=0; k<rightSubtree.size(); k++){
                node* right = rightSubtree[k];
                node* n = new node(i);
                n->left = left;
                n->right = right;
                trees.push_back(n);
            }
        }
    }
    return trees;
}

int main(){

    // int n=5;
    // for(int i=0; i<n; i++){
    //     cout<<i<<"th term: "<<catalan(i)<<endl;
    // }

    vector<node*> trees = constructTree(1, 3);
    for(int i=0; i<trees.size(); i++){
        cout<<i+1<<" : ";
        inorder(trees[i]);
        cout<<endl;
    }

    return 0;
}