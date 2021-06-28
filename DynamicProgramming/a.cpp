#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int fun(int n, int p)
{

    if (n == 1)
        return p;

    if (dp[n][p] != -1)
    {
        cout << dp[n][p] << " " << n << " " << p << endl;
        return dp[n][p];
    }

    int i, ans = 0;

    for (i = 1; i <= (n / 2); i++)
    {
        if (n % i == 0)
        {
            ans = max(ans, fun(i, (n * p) / i));
        }
    }

    return dp[n][p] = (ans + p);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int t;
    scanf("%d ", &t);
    while (t--)
    {

        memset(dp, -1, sizeof(dp));
        int n, i, a;
        cin >> n;

        int ans = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a;
            ans += fun(a, 1);
        }

        cout << ans << endl;
    }
    return 0;
}
