#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution
{

public:
    Node *buildTree(int a[], int n, int currNode)
    {
        if (currNode >= n)
        {
            return NULL;
        }

        if (a[currNode] == 0)
        {
            return NULL;
        }

        Node *root = newNode(a[currNode]);

        int leftChild = (2 * currNode) + 1;
        int rightChild = (2 * currNode) + 2;

        root->left = buildTree(a, n, leftChild);
        root->right = buildTree(a, n, rightChild);

        return root;
    }

    void kSumPaths(Node *root, int k, int s, vector<int> &path)
    {
        
        

        if (root == NULL)
        {
            return;
        }

        path.push_back(root->data);
        s += root->data;

        kSumPaths(root->left, k, s, path);
        kSumPaths(root->right, k, s, path);

        if (s == k)
        {
            for (auto x : path)
                cout << x << " ";
            cout << endl;
        }

        for (int i = path.size() - 1; i > 0; i--)
        {

            s -= path[i];

            if (s == k)
            {
                for (auto x = 0; x < i; x++)
                    cout << path[x] << " ";
                cout << endl;
            }
        }

        path.pop_back();
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t, k;
    cin >> t;

    Solution obj;
    while (t--)
    {
        int n, i;
        cin >> n >> k;

        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Node *root = obj.buildTree(a, n, 0);

        vector<int> path;
        
        
        // O(n)*O(h)
        obj.kSumPaths(root, k, 0, path);
    }

    return 0;
}
