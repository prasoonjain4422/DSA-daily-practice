#include <bits/stdc++.h>
using namespace std;

long dp[201][201][201];
long fun(int n, int g, int i)
{

    if (dp[n][g][i] != -1)
        return dp[n][g][i];

    if ((g == 0) && (n == 0))
    {
        dp[n][g][i] = 1;
        return 1;
    }

    if (g <= 0)
        return 0;

    if (n <= 0)
        return 0;

    cout << n << " " << g << endl;
    long ans = 0;
    for (i; i <= (n - g + 1); i++)
    {
        ans += fun(n - i, g - 1, i);
        cout << n << " " << g << " ";
        cout << "i" << i << " -->" << ans << endl;
    }

    cout << n << " " << g << " ";
    cout << ans << "  anssssssssss" << endl;
    dp[n][g][i] = ans;
    return ans;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, g;
    memset(dp, -1, sizeof(dp));
    cin >> n >> g;

    cout << fun(n, g, 1);

    return 0;
}
