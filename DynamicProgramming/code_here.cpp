#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
const ll M = 1000000007;

void dfs(ll i, vector<bool> &in, vector<ll> adj[])
{

    in[i] = true;

    for (auto x : adj[i])
    {
        if (!in[x])
        {
            dfs(x, in, adj);
        }
    }
}

void solve()
{
    ll i, j, k, n, a, b, m, c, l, r, mid, sum, f;

    // cin >> n >> m;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({5, 1});
    pq.push({2, 1});
    pq.push({4, 1});
    pq.push({1, 3});
    pq.push({3, 2});
    n = 1;

    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();

        if (n == 1)
        {
            pq.push({1, 3});
            pq.push({2, 2});
            n = 0;
        }
    }

    // cout << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
