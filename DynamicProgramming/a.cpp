#include <bits/stdc++.h>
const int M = 1000000007;

using namespace std;
int n, k;

int paint(int i, int d, vector<int> adj[], int dp[][2])
{

    int ans = 0, ans2 = 1;
    if (d <= 0)
    {
        if (dp[i][0] == -1)
        {

            ans = 1;
            for (auto x : adj[i])
            {
                ans = (ans * paint(x, k - 1, adj, dp)) % M;
            }

            dp[i][0] = ans;
        }
        else
        {
            ans = dp[i][0];
        }
    }

    if (dp[i][1] == -1)
    {
        for (auto x : adj[i])
        {
            ans2 = (ans2 * paint(x, d - 1, adj, dp)) % M;
        }

        dp[i][1] = ans2;
    }
    else
    {
        ans2 = dp[i][1];
    }

    return (ans + ans2) % M;
}

int ans = 0;
int fun(int n, vector<int> &a, vector<bool> &vis, int s, int i, int sum)
{
    if (sum == s)
    {
        ans++;
        return true;
    }
    if(sum > s)
    {
        return false;    
    }

    int j;
    for (j = i + 1; j < n; j++)
    {
        if (!vis[j])
        {
            if (fun(n, a, vis, s, j, sum + a[j]))
            {
                vis[j] = true;
                break;
            }
        }
    }

    if (j < n)
        return true;

    return false;
}

int main()
{

    int i, j, p, q, s;

    cin >> n;
    vector<int> a(n);
    vector<bool> vis(n);

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> s;

    for (i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            for (j = i + 1; j < n; j++)
            {
                if (!vis[j])
                {
                    if (fun(n, a, vis, s, j, a[i] + a[j]))
                    {
                        vis[i] = true;
                        vis[j] = true;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

