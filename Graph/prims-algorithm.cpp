#include <bits/stdc++.h>
using namespace std;

int minKey(int V, int adj[V][V], vector<bool> &inc, vector<int> key)
{
    int i, m = INT_MAX, ind;

    for (i = 0; i < V; i++)
    {
        if ((!inc[i]) && (key[i] <= m))
        {
            m = key[i];
            ind = i;
        }
    }

    return ind;
}

vector<int> prims(int V, int adj[V][V], int s)
{

    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> inc(V, false);
    int i, j, k;
    key[s] = 0;

    for (i = 0; i < V - 1; i++)
    {

        j = minKey(V, adj, inc, key);

        inc[j] = true;

        if (key[j] != INT_MAX)
        {
            for (int k = 0; k < V; k++)
            {
                if ((!inc[k]) && (adj[i][k] != 0))
                {
                    if (key[k] > (adj[j][k]))
                    {
                        key[k] = adj[j][k];
                        parent[k] = i;
                    }
                }
            }
        }
    }
    return parent;
}
