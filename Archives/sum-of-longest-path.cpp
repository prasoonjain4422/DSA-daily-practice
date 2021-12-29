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

    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left);

        cout << root->data << "-";

        inorder(root->right);
    }

    pair<int, int> longestPathSum(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};

        // pair<int, int> == pair<height, sum>

        pair<int, int> leftChild = longestPathSum(root->left);
        pair<int, int> rightChild = longestPathSum(root->right);

        if (leftChild.first == rightChild.first)
        {
            return {leftChild.first, max(leftChild.second, rightChild.second) + root->data};
        }
        else if (leftChild.first > rightChild.first)
        {
            return {leftChild.first, leftChild.second + root->data};
        }

        return {rightChild.first, rightChild.second + root->data};
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

        TreeNode *root = treeObject.buildTree(a, n, 0);

        cout << treeObject.longestPathSum(root).second;

        // treeObject.inorder(root);
    }
    return 0;
}
