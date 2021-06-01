#include <bits/stdc++.h>
using namespace std;

//   O(V*E)

void bellman(vector<pair<pair<int, int>, int>> &edges, int V, int E, int s)
{

    vector<int> dist(V, INT_MAX);
    vector<bool> inc(V, false);
    int i, j, k, u, v, w;
    dist[s] = 0;

    for (i = 0; i < V - 1; i++)
    {
        for (int k = 0; k < E; k++)
        {
            u = edges[k].first.first;
            v = edges[k].first.second;
            w = edges[k].second;
            
            if(dist[u] > dist[v] + w)
                dist[u] = dist[v] + w;
        }
    }
    
    
        for (int k = 0; k < E; k++)
        {
            u = edges[k].first.first;
            v = edges[k].first.second;
            w = edges[k].second;
            
            if(dist[u] > dist[v] + w)
            {
                cout<<"Negative weight cycles"<<endl;
                return;
            }
        }
        
    return;
}
