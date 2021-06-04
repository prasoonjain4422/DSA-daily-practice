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
            
            
            if(parent[i] == -1)
            {
                ans[i] = 1;
            }
            if(low[x] > dis[i])
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

    int i, j, k, n, e;
    cin >> n >> e;
    vector<int> adj[n];

    while (e--)
    {
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    vector<int> ans(n, 0);
    vector<bool> vis(n, false);
    vector<int> dis(n, 0);
    vector<int> parent(n, -1);
    vector<int> low(n, 0);
    dfs(0, ans, adj, vis, dis, low, parent);
    
    i = 0;
    for(auto x: ans)
    {
        if(x)
        {
            cout<<i<<" ";
        }
        i++;
    }
            
    return 0;
}
