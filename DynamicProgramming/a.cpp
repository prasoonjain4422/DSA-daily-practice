#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, t, c, i, u, v, j;
    cin >> n >> m >> t >> c;
    bool ch = false;
    vector<int> adj[n + 1];
    vector<bool> vis(n + 1);

    for (i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int, int>> q;
    q.push({1, 0});

    int ans = -1;
    u = 0;
    while (!q.empty())
    {
        i = (q.front()).first;
        v = (q.front()).second;
        q.pop();

        if (i == n)
        {
            if ((ch == false) || (u == v))
            {
                u = v;
                ch = true;
                continue;
            }
            else
            {
                ans = v;
                break;
            }
        }

        vis[i] = true;
        for (j = 0; j < adj[i].size(); j++)
        {
            q.push({adj[i][j], v + 1});
        }
    }

    if (ans == -1)
    {
        cout << "-1" << endl;
    }
    else
    {
        u = ans;
        ans = 0;
        // cout << u << endl;

        i = c;
        u--;
        while (u--)
        {
            if ((i / t) % 2 != 0)
            {
                ans += t - (i % t) + c;
            }

            i = ans+c;
        }

        ans += c;

        cout << ans << endl;
    }

    return 0;
}