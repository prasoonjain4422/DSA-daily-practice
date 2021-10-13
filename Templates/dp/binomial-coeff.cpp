#include <bits/stdc++.h>
#define ll long long
#define endl "\n";
using namespace std;
ll dp[1000];

// Space-optimized dp approach

// nCr = nC(r-1) + (n-1)C(r-1)

ll binomialCoeff(ll n, ll k)
{
    ll i, j;

    dp[0] = 1; // nC0 = 1
    dp[1] = n; // nC1 = n
    for (i = 1; i <= n; i++)
    {
        for (j = min(i, k); j > 0; j--)
            dp[j] = dp[j] + dp[j - 1];
    }

    return dp[k];
}

int main()
{
    ll t, n, k, i, j;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (n == k)
        {
            cout << "1" << endl;
            continue;
        }

        // The value of C(n, k) is
        // C(n, k) = C(n-1, k-1) + C(n-1, k)
        cout << binomialCoeff(n, k) << endl;
    }
    return 0;
}
