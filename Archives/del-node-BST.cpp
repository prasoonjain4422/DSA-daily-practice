#include <bits/stdc++.h>
using namespace std;

// Q - Return the sum of nodes on longest path from root to leave
//     if there are more than one path with same length return sum
//     of maximum sum.

struct Node
{
    int data;
    Node *next = NULL;
};

struct TreeNode
{
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
};

class Tree
{
public:
    TreeNode *root;
    TreeNode *buildTree(int a[], int n, int node)
    {

        if (node < n)
        {
            TreeNode *root = new TreeNode();
            root->data = a[node];

            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            root->left = buildTree(a, n, leftChild);
            root->right = buildTree(a, n, rightChild);

            return root;
        }

        return NULL;
    }

    void insertNodeBST(TreeNode *root, int data)
    {
        while (true)
        {
            if (root->data < data)
            {
                if (root->right == NULL)
                {
                    root->right = new TreeNode();
                    root->right->data = data;
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
            else
            {
                if (root->left == NULL)
                {
                    root->left = new TreeNode();
                    root->left->data = data;
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
        }
    }

    TreeNode *buildBST(int a[], int n)
    {

        // O(NlogN)

        if (n < 1)
            return NULL;

        TreeNode *root = new TreeNode();
        root->data = a[0];

        for (int i = 1; i < n; i++)
        {
            insertNodeBST(root, a[i]);
        }

        return root;
    }

    void inorder(TreeNode *root)
    {
        // O(N) - because we are trasversing every node

        if (root == NULL)
        {
            return;
        }

        inorder(root->left);

        cout << root->data << "-";

        inorder(root->right);
    }

    void delNodeBST(TreeNode *root, int key)
    {

        if (root == NULL)
            return;

        if ((root->left != NULL) && (root->left->data == key))
        {

            if (root->left->left == NULL)
            {
                root->left = root->left->right;
            }
            else if (root->left->right == NULL)
            {
                root->left = root->left->left;
            }
            else
            {

                TreeNode *temp = root->left->left;
                TreeNode *pre = root->left->left;

                while ((temp->right != NULL) || (temp->left != NULL))
                {
                    while (temp->right != NULL)
                    {
                        pre = temp;
                        temp = temp->right;
                    }

                    if (temp->left != NULL)
                    {
                        pre = temp;
                        temp = temp->left;
                    }
                }

                temp->left = root->left->left;
                temp->right = root->left->right;
                root->left = temp;

                if (pre->left == temp)
                {
                    pre->left = NULL;
                }
                else
                {
                    pre->right = NULL;
                }
            }

            return;
        }

        if ((root->right != NULL) && (root->right->data == key))
        {

            if (root->right->left == NULL)
            {
                root->right = root->right->right;
            }
            else if (root->right->right == NULL)
            {
                root->right = root->right->left;
            }
            else
            {

                TreeNode *temp = root->right->left;
                TreeNode *pre = root->right->left;

                while ((temp->right != NULL) || (temp->left != NULL))
                {
                    while (temp->right != NULL)
                    {
                        pre = temp;
                        temp = temp->right;
                    }

                    if (temp->left != NULL)
                    {
                        pre = temp;
                        temp = temp->left;
                    }
                }

                temp->left = root->right->left;
                temp->right = root->right->right;
                root->right = temp;

                if (pre->left == temp)
                {
                    pre->left = NULL;
                }
                else
                {
                    pre->right = NULL;
                }
            }

            return;
        }

        if (root->data > key)
        {
            delNodeBST(root->left, key);
        }
        else
        {
            delNodeBST(root->right, key);
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, n, k;

    Tree treeObject;

    cin >> t;
    while (t--)
    {
        // number of Nodes
        cin >> n;

        // Node *root = objll.buildList(n);
        // obj.printList(root);
        // cout << endl;

        int a[n];

        for (auto &x : a)
            cin >> x;

        int key;
        cin >> key;

        // TreeNode *root = treeObject.buildTree(a, n, 0);
        TreeNode *root = treeObject.buildBST(a, n);

        treeObject.inorder(root);

        treeObject.delNodeBST(root, key);

        cout << endl;
        treeObject.inorder(root);
    }
    return 0;
}
