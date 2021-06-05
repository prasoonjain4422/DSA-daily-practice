#include <bits/stdc++.h>
using namespace std;

int timer = 1;

//  leafs are not articulation points

void dfs(int i, vector<int> &ans, vector<int> adj[], vector<bool> &vis, vector<int> &dis, vector<int> &low, vector<int> &parent)
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

            if (parent[i] == -1)
            {
                ans[i] = 1;
            }
            if (low[x] > dis[i])
            {
                ans[i] = 1;
            }
        }
        else if (x != parent[i])
        {

            low[i] = min(low[i], dis[x]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, k, n, e, s, d;
    cin >> n >> e;
    vector<int> adj[n], adjt[n];

    while (e--)
    {
        cin >> i >> j;
        adj[i].push_back(j);
        adjt[j].push_back(i);
    }
    cin >> s >> d;

    vector<bool> vis(n, false);
    queue<pair<int, int>> q;
    q.push({s, 0});
    vis[s] = true;

    while (!q.empty())
    {

        i = (q.front()).first;
        j = (q.front()).second;
        q.pop();

        if (i == d)
        {
            cout << j;
            return 0;
        }

        for (auto x : adj[i])
        {
            if (!vis[x])
            {
                vis[x] = true;
                q.push({x, j});
            }
        }

        for (auto x : adjt[i])
        {
            if (!vis[x])
            {
                vis[x] = true;
                q.push({x, j + 1});
            }
        }
    }

    cout << "-1";
    return 0;
}
