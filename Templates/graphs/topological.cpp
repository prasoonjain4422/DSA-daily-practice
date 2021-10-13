#include <bits/stdc++.h>
#define ll long long int
#define endl "\n";
using namespace std;
ll n, c = 0;
queue<ll> q;
unordered_map<ll, ll> topology, indegree;

void Topological(map<ll, list<ll>> graph)
{
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        topology[u] = ++c;

        for (auto i = graph[u].begin(); i != graph[u].end(); i++)
        {
            if (--indegree[*i] == 0)
                q.push(*i);
        }
    }
}

int main()
{
    // Graph must be directed

    ll i, j, k, e;
    map<ll, list<ll>> graph;
    c = 0;
    graph.clear();
    indegree.clear();

    cout << "Enter no of nodes: ";
    cin >> n;
    cout << "Enter no of edges: ";
    cin >> e;

    for (i = 0; i < e; i++)
    {
        cin >> j >> k;
        graph[j].push_back(k);
        indegree[k]++;
    }

    for (i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    Topological(graph);

    if (c == n)
    {
        for (i = 1; i <= n; i++)
            cout << topology[i] << " ";
    }
    else
    {
        cout<<"graph has cycles.";
    }
    
}
