#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;

class Solution
{
public:
    long int disarrange(int n)
    {

        if (n < 5)
        {
            return max(n - 1, 0);
        }

        long long int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;

        for (long int i = 4; i <= n; i++)
        {
            dp[i] = ((i - 1) * (dp[i - 1] % M + dp[i - 2] % M)) % M;
        }

        return dp[n];
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.disarrange(N) << "\n";
    }
    return 0;
} // } Driver Code Ends