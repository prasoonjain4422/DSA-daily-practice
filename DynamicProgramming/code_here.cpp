#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

int dfs(vector<int> adj[], vector<bool> &vis, int i)
{

    int ans = 0;
    vis[i] = true;
    for (auto x : adj[i])
    {
        ans += dfs(adj, vis, x);
    }

    return (ans + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, i, j, m, x;

    cin >> n;
    cin >> m;
    cin >> x;
    // cout << "n = " << n;

    vector<int> adj[n];
    vector<bool> vis(n, false);

    // cout << "drd" << endl;
    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;

    for (i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            j = dfs(adj, vis, i);

            if (j <= x)
                ans = max(ans, j);
        }
    }

    cout << ans;

    return 0;
}
