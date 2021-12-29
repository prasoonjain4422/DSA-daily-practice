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

    string dupSubTrees(TreeNode *root, vector<int> &ans, unordered_map<string, bool> &isPresent)
    {

        if (root == NULL)
            return ("");

        string tree = "";

        // tree = "   leftSubtree - parent - rightSubtree   "

        tree = dupSubTrees(root->left, ans, isPresent);

        tree = tree + " - " + to_string(root->data);

        tree = tree + " - " + dupSubTrees(root->right, ans, isPresent);

        if (isPresent[tree])
        {
            ans.push_back(root->data);
        }

        isPresent[tree] = true;

        return tree;
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

    while (t--)
https://www.linkedin.com/in/prasoon-jain-bbb856175/    cin >> t;
    {
        // number of Nodes
        cin >> n;

        // Node *root = objll.buildList(n);
        // obj.printList(root);
        // cout << endl;

        int a[n];

        for (auto &x : a)
            cin >> x;

        vector<int> ans;
        unordered_map<string, bool> isPresent;

        TreeNode *root = treeObject.buildTree(a, n, 0);
        treeObject.dupSubTrees(root, ans, isPresent);

        for (auto &x : ans)
        {
            cout << x << " ";
        }

        // treeObject.inorder(root);
    }
    return 0;
}




//                  1
//          2               2
//      4       5       4       5








