#include <bits/stdc++.h>
#define ll long long
#define endl "\n";
using namespace std;

// Given weights and values of n items, put these
// items in a knapsack of capacity W to get the
// maximum total value in the knapsack.
// Time Complexity: O(N*W).


ll knapsack(ll n, ll wc, vector<ll> v, vector<ll> w)
{
    ll it, jwc;
    ll dp[n + 1][wc + 1];

    for (it = 0; it <= n; it++)
    {
        for (jwc = 0; jwc <= wc; jwc++)
        {
            if ((it == 0) || (jwc == 0))
            {
                dp[it][jwc] = 0;
            }
            else if (w[it - 1] <= jwc)
            {
                dp[it][jwc] = max(dp[it - 1][jwc], dp[it - 1][jwc - w[it - 1]] + v[it - 1]);
            }
            else
            {
                dp[it][jwc] = dp[it - 1][jwc];
            }
        }
    }

    return dp[n][wc];
}

int main()
{
    ll t, n, wc, i, ans;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> wc;
        vector<ll> v(n), w(n);

        for (i = 0; i < n; i++)
            cin >> v[i];

        for (i = 0; i < n; i++)
            cin >> w[i];

        cout << knapsack(n, wc, v, w) << endl;
    }
    return 0;
}
