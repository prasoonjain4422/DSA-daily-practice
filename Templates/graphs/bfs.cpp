#include <bits/stdc++.h>
#define ll long long int
#define endl "\n";
using namespace std;
ll n;
vector<bool> visited(10000);

void BFS(map<ll, list<ll>> graph, ll u)
{
    queue<ll> q;
    q.push(u);

    while (!q.empty())
    {
        u = q.front();
        q.pop();

        cout << u << " ";
        visited[u] = true;

        for (auto i = graph[u].begin(); i != graph[u].end(); i++)
        {
            if (!visited[*i])
            {
                q.push(*i);
            }
        }
    }
}

int main()
{
    ll i, j, k, e;
    map<ll, list<ll>> graph;
    graph.clear();
    visited.clear();

    cout << "Enter no of nodes: ";
    cin >> n;
    cout << "Enter no of edges: ";
    cin >> e;

    for (i = 0; i < e; i++)
    {
        cin >> j >> k;
        graph[j].push_back(k);
        graph[k].push_back(j);
    }

    for (i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            BFS(graph, i);
        }
    }
}
