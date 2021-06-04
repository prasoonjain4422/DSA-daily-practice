// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V)
{

    vector<int> color(V, -1);
    int i, j, k, c = 1;
    queue<int> q;

    for (k = 0; k < V; k++)
    {
        if (color[k] == -1)
        {
            q.push(k);
            while (!q.empty())
            {
                i = q.front();
                q.pop();

                if (color[i] != -1)
                    continue;

                c = 1;
                for (j = 0; j < V; j++)
                {
                    if (graph[i][j] == 1)
                    {

                        if (color[j] == -1)
                        {
                            q.push(j);
                        }
                        else
                        {
                            if (color[j] == c)
                            {
                                c++;
                            }
                        }

                        if (c > m)
                            return false;
                    }
                }
                color[i] = c;
            }
        }
    }
    return true;
}

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends