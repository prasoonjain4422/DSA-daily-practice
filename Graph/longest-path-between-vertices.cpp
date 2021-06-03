// CPP program for the above approach
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{

    // A node class which stores the color and the edges
    // connected to the node
public:
    int color = 1;
    set<int> edges;
};

int canPaint(vector<node> &nodes, int n, int m)
{

    // Create a visited array of n
    // nodes, initialized to zero
    vector<int> visited(n + 1, 0);

    // maxColors used till now are 1 as
    // all nodes are painted color 1
    int maxColors = 1;

    // Do a full BFS traversal from
    // all unvisited starting points
    for (int sv = 1; sv <= n; sv++)
    {

        if (visited[sv])
            continue;

        // If the starting point is unvisited,
        // mark it visited and push it in queue
        visited[sv] = 1;
        queue<int> q;
        q.push(sv);

        // BFS Travel starts here
        while (!q.empty())
        {
            
            
            int top = q.front();
            q.pop();

            // Checking all adjacent nodes
            // to "top" edge in our queue
            for (auto it = nodes[top].edges.begin();
                 it != nodes[top].edges.end(); it++)
            {

                // IMPORTANT: If the color of the
                // adjacent node is same, increase it by 1
                if (nodes[top].color == nodes[*it].color)
                    nodes[*it].color += 1;

                // If number of colors used shoots m, return
                // 0
                maxColors = max(maxColors, max(nodes[top].color,
                                               nodes[*it].color));
                if (maxColors > m)
                    return 0;

                // If the adjacent node is not visited,
                // mark it visited and push it in queue
                if (!visited[*it])
                {
                    visited[*it] = 1;
                    q.push(*it);
                }
            }
        }
    }

    return 1;
}

// Driver code
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 11;
    bool graph[n][n] = {
         {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
         {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
         {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1},
         {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
         {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
         {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    
    int m = 4; // Number of colors

    // Create a vector of n+1
    // nodes of type "node"
    // The zeroth position is just
    // dummy (1 to n to be used)
    vector<node> nodes(n + 1);

    // Add edges to each node as per given input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j])
            {
                // Connect the undirected graph
                nodes[i].edges.insert(i);
                nodes[j].edges.insert(j);
            }
        }
    }

    // Display final answer
    cout << canPaint(nodes, n, m);
    cout << "\n";

    return 0;
}
