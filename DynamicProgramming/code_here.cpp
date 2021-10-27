#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
const ll M = 1000000007;

void solve()
{
    ll i, j, k, n, m, c, l, r, mid, sum, f;

    cin >> n;
    vector<ll> a(n), b(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<ll> dp(n + 1, INT_MAX);

    dp[0] = 0;
    // cout << dp[0] << endl;
    unordered_map<ll, ll> um;

    for (i = 1; i <= n; i++)
    {
        if ((i - a[i - 1]) <= 0)
        {
            dp[i] = 1LL;
            um[i] = 0;
        }
    }

    for (i = 1; i <= n; i++)
    {
        // cout << i << endl;
        
        if(i + b[i])
        
        for (j = a[i - 1]; j > 0; j--)
        {
            if (i - j > 0)
            {
                if (dp[i] > dp[max(0LL, i - j + b[i - j - 1])] + 1)
                {
                    dp[i] = dp[max(0LL, i - j + b[i - j - 1])] + 1;
                    um[i] = i - j;
                }
            }
            else
            {
                if (dp[i] > 1)
                {
                    dp[i] = 1LL;
                    um[i] = 0;
                }
            }
            // cout << i << " -- " << dp[i] << " -- " << um[i] << " ";
        }
        // cout << endl;
    }

    if (dp[n] != INT_MAX)
    {
        cout << dp[n] << endl;
        i = n;
        while (um[i])
        {
            cout << um[i] << " ";
            i = um[i];
        }
        cout << um[i];
    }
    else
    {
        cout << "-1";
    }

    cout << endl;
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
    // cin >> t;

    // while (t--)
    // {
    solve();
    // }

    return 0;
}