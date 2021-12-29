#include <bits/stdc++.h>
using namespace std;

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

    TreeNode *BSTfromPreorder(int a[], int n, int &preIndex, int low, int high)
    {
        if (preIndex < n)
        {
            if ((a[preIndex] >= low) && (a[preIndex] <= high))
            {
                // cout << "fdyg  " << preIndex << endl;
                TreeNode *root = new TreeNode();
                root->data = a[preIndex];

                int currData = a[preIndex];

                preIndex++;
                root->left = BSTfromPreorder(a, n, preIndex, low, currData);

                root->right = BSTfromPreorder(a, n, preIndex, currData, high);

                // cout << currData;

                // if (root->left != NULL)
                // {
                //     cout << "  -" << root->left->data;
                // }

                // if (root->right != NULL)
                // {
                //     cout << "  -" << root->right->data;
                // }
                // cout << endl;
                
                
                return root;
            }
        }
        return NULL;
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

        // int key;
        // cin >> key;
        // TreeNode *root = treeObject.buildTree(a, n, 0);

        if (n > 0)
        {
            int preIndex = 0;
            TreeNode *root = treeObject.BSTfromPreorder(a, n, preIndex, INT_MIN, INT_MAX);
            treeObject.inorder(root);
        }
    }
    return 0;
}
