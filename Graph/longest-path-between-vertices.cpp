#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, k, n, e, s, d, w;
    cin >> n >> e;
    vector<pair<int, int>> adj[n];
    vector<bool> vis(n, false);
    vector<int> ind(n, 0);
    queue<int> q;
    vector<int> topo;

    while (e--)
    {
        cin >> i >> j >> w;
        adj[i].push_back({j, w});
        ind[j]++;
    }
    cin >> s;
    
    
    // topological sort is only for DAG
    
    for (i = 0; i < n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        i = q.front();
        q.pop();

        topo.push_back(i);
        cout << i << " ";

        for (auto x : adj[i])
        {
            ind[x.first]--;
            if (ind[x.first] == 0)
                q.push(x.first);
        }
    }
    cout << endl;

    int dist[n];
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    for (auto x : adj[s])
    {
        dist[x.first] = x.second;
    }


    for (j = 0; j < topo.size(); j++)
    {
        i = topo[j];
        if (dist[i] != -1)
        {
            for (auto x : adj[i])
            {
                if (dist[x.first] < (dist[i] + x.second))
                {
                    dist[x.first] = (dist[i] + x.second);
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}
