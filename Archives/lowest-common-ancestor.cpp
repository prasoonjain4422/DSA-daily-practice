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

    TreeNode *lca(TreeNode *root, int key1, int key2)
    {

        //  O(N)

        if (root == NULL)
            return NULL;

        if (root->data == key1)
        {
            return root;
        }

        if (root->data == key2)
        {
            return root;
        }

        TreeNode *leftChild = lca(root->left, key1, key2);
        TreeNode *rightChild = lca(root->right, key1, key2);

        if ((leftChild != NULL) && (rightChild != NULL))
        {
            return root;
        }
        else if (leftChild != NULL)
        {
            return leftChild;
        }

        return rightChild;
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

        int key1, key2;
        cin >> key1 >> key2;

        int preIndex = 0;
        TreeNode *root = treeObject.buildTree(a, n, 0);
        root = treeObject.lca(root, key1, key2);

        // treeObject.inorder(root);

        cout << root->data;
    }
    return 0;
}
