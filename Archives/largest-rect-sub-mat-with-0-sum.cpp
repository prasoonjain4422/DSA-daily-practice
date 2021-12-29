#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const ll M = 1000000007;

void solve()
{
    ll i, j, k, n, m, mid, sum, f, x, y, r, l, ans, finalAns, w, h;

    cin >> n;
    vector<vector<ll>> mat(n, vector<ll>(0, n));

    ll p[n][n];

    memset(p, 0, sizeof(p));

    for (i = 0; i < n; i++)
    {
        mat[i].resize(n);
        for (j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        p[i][0] = mat[i][0];
        p[0][i] = mat[0][i];
    }

    for (i = 1; i < n; i++)
    {
        p[i][0] = mat[i][0] + p[i - 1][0];
        p[0][i] = mat[0][i] + p[0][i - 1];
    }

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            p[i][j] = mat[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
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
