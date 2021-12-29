#include <bits/stdc++.h>
using namespace std;


// Do the inorder traversal of tree and store the result in array (array will be sorted)        ---O(n)
// now make a balanced bst with the sorted array in O(n) time                                   ---O(n)



Node *buildTree(vector<int> &nodes_data, int j, int n)
{

    Node *root = new Node();
    root->data = nodes_data[j];

    // cout << nodes_data[j] << "^";
    // cout << j << "-";
    // cout << ((2 * j) + 1) << " ";
    if (((2 * j) + 1) < n)
    {
        if (nodes_data[((2 * j) + 1)] != 0)
        {
            root->left = buildTree(nodes_data, ((2 * j) + 1), n);
        }
    }

    // cout << nodes_data[j] << "^";
    // cout << j << "-";
    // cout << ((2 * j) + 2) << " ";
    if (((2 * j) + 2) < n)
    {
        if (nodes_data[((2 * j) + 2)] != 0)
        {
            root->right = buildTree(nodes_data, ((2 * j) + 2), n);
        }
    }

    return root;
}

int solve(Node *root)
{
    
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k;

    //  number of nodes in complete binary tree
    cin >> n;

    vector<int> nodes_data(n, 0);

    //  array representation of binary tree
    //  left child index = 2*(parent index) + 1
    //  right child index = 2*(parent index) + 2

    //  if nodes_data[i] == 0, then node i does not exist

    for (i = 0; i < n; i++)
    {
        cin >> nodes_data[i];
    }

    struct Node *root;
    root = buildTree(nodes_data, 0, n);

    fans = 0;
    int ans = solve(root);

    cout << endl;
    cout << max(ans, fans) << endl;

    return 0;
}
