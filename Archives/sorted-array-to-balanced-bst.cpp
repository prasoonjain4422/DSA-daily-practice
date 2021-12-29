#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const ll M = 1000000007;

// Get the middle of the array and make it root.
// Recursively do same for left and right subtree.

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

Node *bbst(vector<ll> &a, int l, int r)
{

    if (l > r)
    {
        return NULL;
    }

    int m = l + (r - l) / 2;

    if (a[m] == 0)
    {
        return NULL;
    }

    Node *temp = new Node();
    temp->data = a[m];

    temp->left = bbst(a, l, m - 1);
    temp->right = bbst(a, m + 1, r);

    return temp;
}

void solve()
{
    ll i, j, k, n, m, mid, sum, f, v, x, y, r, l, ans, ans2;
    cin >> n;

    vector<ll> a(n);

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Node *root = bbst(a, 0, n - 1);

    cout << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
