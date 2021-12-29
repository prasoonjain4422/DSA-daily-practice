#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

class Solution
{
public:
    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);

        cout << root->data << " ";

        inorder(root->right);
    }

    Node *makeBst(int pre[], int low, int high)
    {

        if (low > high)
        {
            return NULL;
        }
        else if (low == high)
        {
            Node *root = new Node();
            root->data = pre[low];
            return root;
        }

        Node *root = new Node();
        root->data = pre[low];

        int i;
        for (i = low + 1; i <= high; i++)
        {
            if (pre[i] > pre[low])
            {
                break;
            }
        }

        root->left = makeBst(pre, low + 1, i - 1);
        root->right = makeBst(pre, i, high);

        return root;
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
    Solution obj;

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Node *root = obj.makeBst(a, 0, n - 1);

    obj.inorder(root);

    return 0;
}