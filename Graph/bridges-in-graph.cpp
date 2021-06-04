#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int i, vector<pair<int, int>> &ans, vector<int> adj[], vector<bool> &vis, vector<int> &dis, vector<int> &low, vector<int> &parent)
{

    vis[i] = true;
    dis[i] = timer++;
    low[i] = dis[i];

    for (auto x : adj[i])
    {
        if (!vis[x])
        {
            parent[x] = i;
            dfs(x, ans, adj, vis, dis, low, parent);

            low[i] = min(low[i], low[x]);

            if (low[x] > dis[i])
            {
                // ans.push_back({i, x});
                cout << i << " " << x << endl;
            }
        }
        else if (x != parent[i])
        {
            if (low[i] > dis[x])
            {
                low[i] = dis[x];
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, k, n, e;
    cin >> n >> e;
    vector<int> adj[n];

    while (e--)
    {
        cin >> i >> j;
        adj[i].push_back(j);
    }

    vector<pair<int, int>> ans;
    vector<bool> vis(n, false);
    vector<int> dis(n, 0);
    vector<int> parent(n, -1);
    vector<int> low(n, 0);
    dfs(0, ans, adj, vis, dis, low, parent);

    return 0;
}