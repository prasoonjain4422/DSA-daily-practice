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

    ll dp[n][n];

    for (i = 0; i < n; i++)
    {
        mat[i].resize(n);
        for (j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            // cout << mat[i][j] << " ";
            dp[i][j] = mat[i][j];
        }
        // cout << endl;
    }

    ans = 0;
    for (i = 1; i < n; i++)
    {
        if (mat[i][0] == 1)
        {
            dp[i][0] = dp[i][0] + dp[i - 1][0];
            ans = max(ans, dp[i][0]);
        }

        if (mat[0][i] == 1)
        {
            dp[0][i] = dp[0][i] + dp[0][i - 1];
            ans = max(ans, dp[0][i]);
        }
    }

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                if ((mat[i - 1][j] == 1) && (mat[i][j - 1] == 1))
                {
                    dp[i][j] = 1 + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans << endl;
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
