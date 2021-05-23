// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
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

    int t, n, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);

        for (i = 0; i < n; i++)
            cin >> a[i];

        Node *root = new Node(a[n - 1]);
        a[n-1] = -1;
        Node *it = NULL;

        for (i = n - 2; i >= 0; i--)
        {
            it = root;

            while (it->data < a[i])
            {
                if (it->right == NULL)
                    break;
                else
                    it = it->right;
            }

            if (it->data < a[i])
            {
                it->right = new Node(a[i]);
                a[i] = -1;
            }
            else
            {
                while (it->left != NULL)
                {
                    if (it->left->data < a[i])
                        break;
                    else
                        it = it->left;
                }
                
                Node *t = it->left;
                it->left = new Node(a[i]);
                a[i] = it->data;
                it = it->left;
                it->left = t;
                
            }            
        }

        for (i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    return 0;
}
