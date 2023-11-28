#include <iostream>
#include <stack>
#include "bst.hpp"

void zigzagTraversal(node *root)
{
    if(root==NULL){
        return;
    }
    stack<node *> curr, next;

    bool leftToRight = true;

    curr.push(root);
    while (!curr.empty())
    {
        node *temp = curr.top();
        curr.pop();

        if (temp)
        {
            cout << temp->data << " ";
        }

        if (leftToRight)
        {
            if (temp->left)
            {
                next.push(temp->left);
            }
            if (temp->right)
            {
                next.push(temp->right);
            }
        }
        else
        {
            if (temp->right)
            {
                next.push(temp->right);
            }
            if (temp->left)
            {
                next.push(temp->left);
            }
        }

        if (curr.empty())
        {
            leftToRight = false;
            stack<node *> temp = curr;
            curr = next;
            next = temp;
        }
    }
}

int main()
{
    node *root = new node(12);
    root->left = new node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);

    cout<<"Zigzag Traversal: ";
    zigzagTraversal(root);
    cout<<endl;

    return 0;
}