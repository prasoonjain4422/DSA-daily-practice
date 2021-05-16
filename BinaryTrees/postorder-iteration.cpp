#include <bits/stdc++.h>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Recursive function to perform preorder traversal on the tree
void postorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    stack<int> o;
    s.push(root);

    while (!s.empty())
    {

        root = s.top();
        s.pop();
        o.push(root->data);
        if (root->left != NULL)
            s.push(root->left);

        if (root->right != NULL)
            s.push(root->right);
    }

    while (!o.empty())
    {
        cout << o.top() << " ";
        o.pop();
    }
}

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    postorder(root);

    return 0;
}