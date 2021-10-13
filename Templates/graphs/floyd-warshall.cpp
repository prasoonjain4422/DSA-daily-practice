#include <bits/stdc++.h>
#define ll long long
#define endl "\n";
using namespace std;
ll t, n, e, i, j, u, v, ans;

//--> Time Complexity is O(n3);
//--> The problem is to find shortest distances between every
//    pair of vertices in a given
//    edge weighted directed Graph.


void floydWarshall(vector<vector<ll>> graph)
{

    vector<vector<ll>> dist(n);

    for (i = 0; i < n; i++)
    {
        dist[i].resize(n);
        for (j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
        }
        

        for (u = 0; u < n; u++)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (dist[i][j] > dist[i][u] + dist[u][j])
                        dist[i][j] = dist[i][u] + dist[u][j];
                }
            }
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> e;
        vector<vector<ll>> graph(n);
        for (i = 0; i < n; i++)
        {
            graph[i].resize(n);
            for (j = 0; j < n; j++)
            {
                graph[i][j] = 1e9;
            }
        }

        for (i = 0; i < e; i++)
        {
            cin >> u >> v;
            cin >> graph[u][v];
        }

        floydWarshall(graph);
    }
    return 0;
}
