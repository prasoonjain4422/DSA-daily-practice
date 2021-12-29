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

class LinkedList
{
    Node *root;

public:
    Node *buildList(int n)
    {

        if (n == 0)
            return NULL;

        int currData;

        cin >> currData;
        Node *root = new Node;
        root->data = currData;
        Node *temp = root;

        for (int i = 1; i < n; i++)
        {
            cin >> currData;

            temp->next = new Node();
            temp = temp->next;
            temp->data = currData;
        }

        return root;
    }

    void printList(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        printList(root->next);
    }
};

class Tree
{
public:
    TreeNode *root;
    TreeNode *buildTree(int in[], int pre[], int low, int high, int &preIndex)
    {
        if (low <= high)
        {
            for (int i = low; i <= high; i++)
            {
                if (pre[preIndex] == in[i])
                {
                    TreeNode *root = new TreeNode();
                    root->data = pre[preIndex];
                    preIndex++;
                    
                    root->left = buildTree(in, pre, low, i - 1, preIndex);
                    root->right = buildTree(in, pre, i + 1, high, preIndex);
                    return root;
                }
            }
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
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, n, k;

    LinkedList llObject;
    Tree treeObject;

    cin >> t;
    while (t--)
    {
        // number of Nodes
        cin >> n;

        // Node *root = objll.buildList(n);
        // obj.printList(root);
        // cout << endl;

        int in[n], pre[n];

        for (auto &x : in)
            cin >> x;

        for (auto &x : pre)
            cin >> x;

        int preIndex = 0;
        TreeNode *root = treeObject.buildTree(in, pre, 0, n - 1, preIndex);

        treeObject.inorder(root);
    }
    return 0;
}
