#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr)
{
    for(int i=start; i<=end; i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

node *buildTree1(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];

    idx++;
    node* nod = new node(curr);
    
    if(start == end){
        return nod;
    }


    int pos = search(inorder, start, end, curr);
    nod->left = buildTree1(preorder, inorder, start, pos - 1);
    nod->right = buildTree1(preorder, inorder, pos + 1, end);

    return nod;
}

node* buildTree2(int postorder[], int inorder[], int start, int end){
    
    static int idx = 4;
    if(start>end){
        return NULL;
    }

    int val = postorder[idx];
    idx--;
    node* curr = new node(val);
    if(start==end){
        return curr;
    }

    int pos = search(inorder, start, end, val);
    curr->right = buildTree2(postorder, inorder, pos+1, end);
    curr->left = buildTree2(postorder, inorder, start, pos-1);

    return curr;

}

void inorder(node *root)
{
    if (root == NULL)
    {

        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int postorder[] =  {4, 2, 5, 3, 1};
    int inordr[] = {4, 2, 1, 5, 3};

    node* root1= buildTree1(preorder, inordr, 0, 4);
    node* root2= buildTree2(preorder, inordr, 0, 4);
    inorder(root1);
    cout<<endl;
    inorder(root2);
}