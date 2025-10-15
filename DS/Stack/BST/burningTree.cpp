#include<iostream>
#include<map>
#include<queue>
#include "bst.hpp"

using namespace std;

// create mapping, return target node
node* createParentMapping(node* root, int target, map<node*, node*> &nodeToParent){

    if(root==NULL){
        return NULL;
    }

    node* res = NULL;
    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front->data==target){
            res = front;
        }

        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(node* root,  map<node*, node*> &nodeToParent){
    map<node*, bool> visited;
    queue<node*> q;

    q.push(root);
    visited[root] = 1;

    int ans = 0;
    bool flag = 0;

    while(!q.empty()){
        int size = q.size();

        for(int i=0; i<size; i++){
            node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                q.push(front->left);
                visited[front->left] = 1;
                flag = 1;
            }
            if(front->right && !visited[front->right]){
                q.push(front->right);
                visited[front->right] = 1;
                flag = 1;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
                flag = 1;
            }
        }
        if(flag==1){
            ans++;
        }
    }
    return ans;
}

int minTime(node* root, int target){

}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    int target = 5;
    
    map<node*, node*> nodeToParent;
    node* targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);

    cout<< ans;

    return 0;
}