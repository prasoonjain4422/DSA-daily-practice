#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left = NULL;
    treeNode *right = NULL;
};

class Solution
{
public:
    treeNode *buildTree(int a[], int n, int parent)
    {

        if (parent >= n)
        {
            return NULL;
        }

        if (a[parent] == 0)
        {
            return NULL;
        }

        treeNode *root = new treeNode();

        root->data = a[parent];

        int leftChild = (2 * parent) + 1;
        int rightChild = (2 * parent) + 2;

        root->left = buildTree(a, n, leftChild);
        root->right = buildTree(a, n, rightChild);

        // cout << root->data << " ------- ";
        // if (root->left != NULL)
        //     cout << root->left->data << " ";
        // if (root->right != NULL)
        //     cout << root->right->data;
        
        
        return root;
    }

    void leftBoundary(treeNode *root)
    {
        if (root == NULL)
            return;

        // if node is leaf node
        if ((root->left == NULL) && (root->right == NULL))
            return;

        cout << root->data << " ";

        if (root->left != NULL)
        {
            leftBoundary(root->left);
        }
        else
        {
            leftBoundary(root->right);
        }
    }

    void rightBoundary(treeNode *root)
    {
        if (root == NULL)
            return;

        // if node is leaf node
        if ((root->left == NULL) && (root->right == NULL))
        {
            return;
        }

        if (root->right != NULL)
        {
            rightBoundary(root->right);
        }
        else
        {
            rightBoundary(root->left);
        }

        cout << root->data << " ";
    }

    void leafNodes(treeNode *root)
    {
        if (root == NULL)
            return;

        // if node is leaf node
        if ((root->left == NULL) && (root->right == NULL))
        {
            cout << root->data << " ";
            return;
        }

        if (root->left != NULL)
        {
            leafNodes(root->left);
        }

        if (root->right != NULL)
        {
            leafNodes(root->right);
        }
    }

    void boundaryTraversal(treeNode *root)
    {

        if (root == NULL)
            return;

        cout << root->data << " ";
        // printing left boundary in top down manner but without leaf nodes
        leftBoundary(root->left);

        cout << endl;

        // printing leaf nodes from left to right
        leafNodes(root);

        cout << endl;
        // printing left boundary in bottom up manner but without leaf nodes
        rightBoundary(root->right);
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    Solution obj;
    while (t--)
    {
        //taking size of array of complete binary tree
        cin >> n;
        int a[n];

        //taking input of tree
        for (int i = 0; i < n; i++)
            cin >> a[i];

        treeNode *root = obj.buildTree(a, n, 0);

        obj.boundaryTraversal(root);

        // for (int i = 0; i < n; i++)
        //     cout << a[i] << " ";
    }
}
