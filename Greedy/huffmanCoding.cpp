#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = right = nullptr;
    }
};

class cmp{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

void traverse(node* root, vector<string> &ans, string temp){

        if(root->left==NULL && root->right==NULL){
            ans.push_back(temp);
        }

        traverse(root->left, ans, temp+'0');
        traverse(root->right, ans, temp+'1');
}

vector<string> huffmanCoding(string S, vector<int> f, int n){

    priority_queue<node*, vector<node*>, cmp> pq;

    for(int i=0; i<n; i++){
        node* temp = new node(f[i]);
        pq.push(temp);
    }

    while(pq.size()>1){
        node* first = pq.top();
        pq.pop();

        node* second = pq.top();
        pq.pop();

        node* newNode = new node(first->data + second->data);
        newNode->left = first;
        newNode->right = second;

        pq.push(newNode);
    }

    node* root = pq.top();
    vector<string> ans;
    string temp = "";
    traverse(root, ans, temp);

    return ans;
}

int main(){
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int n = 6;

    vector<string> ans = huffmanCoding(S, f, n);

    for(int i=0; i<ans.size(); i++){
       cout<<ans[i];
    } cout<<endl;

    return 0;
}