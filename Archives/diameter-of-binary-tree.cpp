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
    TreeNode *root;

public:
    TreeNode *buildTree(int a[], int n, int node)
    {
        if (node < n)
        {
            TreeNode *root = new TreeNode();
            root->data = a[node];

            root->left = buildTree(a, n, node * 2 + 1);
            root->right = buildTree(a, n, node * 2 + 2);

            return root;
        }

        return NULL;
    }

    pair<int, int> diameter(TreeNode *root)
    {

        if (root == NULL)
        {
            return {0, 0};
        }

        pair<int, int> leftSub = diameter(root->left);
        pair<int, int> rightSub = diameter(root->right);

        int dia = max(leftSub.first, rightSub.first);
        dia = max(dia, leftSub.second + rightSub.second + 1);

        return {dia, max(leftSub.second, rightSub.second) + 1};
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

        int a[n];

        for (auto &x : a)
            cin >> x;

        TreeNode *root = treeObject.buildTree(a, n, 0);

        cout << treeObject.diameter(root).first;
    }

    return 0;
}
