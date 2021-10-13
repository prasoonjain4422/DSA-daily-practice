#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
const ll M = 1000000007;

ll power(ll x, ll y)
{

    if (y == 0)
        return 1;

    ll p = power(x, y / 2) % M;
    p = (p * p) % M;

    if (y % 2 != 0)
        p = (p * x) % M;

    return p;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return ((a * b) / gcd(a, b));
}



void dfs(map<ll, ll> &ans, vector<ll> &outtime, vector<bool> &vis)
{
    
    
}

void solve()
{
    ll i, j, k, n, b, m, c, l, r, mid, sum;

    cin >> n >> k;

    map<ll, ll> ans;
    vector<ll> deg(n + 1), outtime(n + 1);
    vector<bool> vis(n + 1, false);
    vector<ll> adj[n + 1];

    for (i = 0; i < n - 1; i++)
    {
        cin >> b >> c;
        adj[b].push_back(c);
        adj[c].push_back(b);
        deg[b]++;
        deg[c]++;
    }
    // cout << "      " << n << " -- " << k << endl;

    for (i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
        {
            vis[i] = true;
            outtime[i] = 1;
            ans[1]++;
        }
    }

    if (k == 1)
    {
        cout << n - ans[1] << endl;
        return;
    }

    for (i = 1; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(ans, );
        }
    }
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
