// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int dp[1001];

class Solution
{
public:
    int coinGame(int n, int x, int y)
    {
        // cout << n << endl;
        if (n < 0)
        {
            return 1;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        if (n > 1)
        {
            if ((coinGame(n - 1 - 1, x, y) == 1) && (coinGame(n - 1 - x, x, y) == 1) && (coinGame(n - 1 - y, x, y) == 1))
            {
                return dp[n] = 1;
            }
        }

        if (n > x)
        {
            if ((coinGame(n - x - 1, x, y) == 1) && (coinGame(n - x - x, x, y) == 1) && (coinGame(n - x - y, x, y) == 1))
            {
                return dp[n] = 1;
            }
        }

        if (n > y)
        {
            if ((coinGame(n - y - 1, x, y) == 1) && (coinGame(n - y - x, x, y) == 1) && (coinGame(n - y - y, x, y) == 1))
            {
                return dp[n] = 1;
            }
        }

        return dp[n] = 0;
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[x] = 1;
        dp[y] = 1;
        Solution obj;
        int ans = obj.coinGame(n, x, y);
        // cout << "ans = ";
        cout << ans << "\n";
    }
    return 0;
}
