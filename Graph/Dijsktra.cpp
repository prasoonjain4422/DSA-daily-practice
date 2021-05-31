#include <bits/stdc++.h>
using namespace std;

int minDist(int V, int adj[V][V], vector<bool> &inc, vector<int> dist)
{
    int i, m = INT_MAX, ind;

    for (i = 0; i < V; i++)
    {
        if ((!inc[i]) && (dist[i] <= m))
        {
            m = dist[i];
            ind = i;
        }
    }

    return ind;
}

int * dijsktra(int V, int adj[V][V], int s)
{

    vector<int> dist(V, INT_MAX);
    vector<bool> inc(V, false);
    int i, j, k;
    dist[s] = 0;

    for (i = 0; i < V - 1; i++)
    {

        j = minDist(V, adj, inc, dist);

        inc[j] = true;

        if (dist[j] != INT_MAX)
        {
            for (int k = 0; k < V; k++)
            {
                if ((!inc[k]) && (adj[i][k] != 0))
                {
                    if (dist[k] > (adj[j][k] + dist[j]))
                    {
                        dist[k] = adj[j][k] + dist[j];
                    }
                }
            }
        }
    }
    return dist;   
}
