#include <iostream>
#include "bst.hpp"

using namespace std;

bool identicalBST(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    else
    {
        bool a = root1->data == root2->data;
        bool b = identicalBST(root1->left, root2->left);
        bool c = identicalBST(root1->right, root2->right);

        if (a && b && c)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // Tree 1
    node *root1 = new node(1);
    root1->right = new node(3);
    root1->right->left = new node(2);
    root1->right->right = new node(5);

    // Tree 2
    node *root2 = new node(1);
    root2->right = new node(3);
    root2->right->left = new node(2);
    root2->right->right = new node(5);

    // call to function
    if (identicalBST(root1, root2))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }

    return 0;
}