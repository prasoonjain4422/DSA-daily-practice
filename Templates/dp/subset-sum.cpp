#include <bits/stdc++.h>
#define ll long long
#define endl "\n";
using namespace std;
vector<ll> se(1000);
ll t, n;

bool isSubsetSum(ll sum)
{
    ll i, j;
    bool dp[n + 1][sum + 1];

    for (i = 0; i < n; i++)
        dp[i][0] = true;

    for (i = 1; i < n; i++)
        dp[0][i] = false;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= sum; j++)
        {
            if (j < se[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - se[i - 1]];
        }
    }
    return dp[n][sum];
}

int main()
{
    ll i, j, sum;
    cin >> t;
    while (t--)
    {
        cin >> n >> sum;

        for (i = 0; i < n; i++)
            cin >> se[i];

        if (isSubsetSum(sum))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
