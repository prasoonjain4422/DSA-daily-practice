#include <bits/stdc++.h>
const int M = 1000000007;

using namespace std;
int n, k;

int paint(int i, int d, vector<int> adj[], int dp[][2])
{

    int ans = 0, ans2 = 1;
    if (d <= 0)
    {
        if (dp[i][0] == -1)
        {

            ans = 1;
            for (auto x : adj[i])
            {
                ans = (ans * paint(x, k - 1, adj, dp)) % M;
            }

            dp[i][0] = ans;
        }
        else
        {
            ans = dp[i][0];
        }
    }

    if (dp[i][1] == -1)
    {
        for (auto x : adj[i])
        {
            ans2 = (ans2 * paint(x, d - 1, adj, dp)) % M;
        }

        dp[i][1] = ans2;
    }
    else
    {
        ans2 = dp[i][1];
    }

    return (ans + ans2) % M;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, p;

    cin >> n;
    cin >> k;

    int dp[n + 1][2];
    memset(dp, -1, sizeof(dp));

    vector<int> adj[n + 1];
    int root;

    for (i = 1; i <= n; i++)
    {
        cin >> p;
        if (p == -1)
            root = i;
        else
            adj[p].push_back(i);
    }

    cout << paint(root, 0, adj, dp) << endl;

    return 0;
}