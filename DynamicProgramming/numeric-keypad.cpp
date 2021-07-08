// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long getCount(int n)
    {

        int dp[n + 1][10];
        int i, j;
        memset(dp, 0, sizeof(dp));

        for (i = 0; i < 10; i++)
        {
            dp[1][i] = 1;
        }

        for (i = 2; i <= n; i++)
        {
            for (j = 0; j < 10; j++)
            {

                dp[i][j] += dp[i - 1][j];
                switch (j)
                {
                case 0:
                    dp[i][j] += dp[i - 1][8];
                    break;
                case 1:
                    dp[i][j] += dp[i - 1][2];
                    dp[i][j] += dp[i - 1][4];
                    break;
                case 2:
                    dp[i][j] += dp[i - 1][1];
                    dp[i][j] += dp[i - 1][3];
                    dp[i][j] += dp[i - 1][5];
                    break;
                case 3:
                    dp[i][j] += dp[i - 1][2];
                    dp[i][j] += dp[i - 1][6];
                    break;
                case 4:
                    dp[i][j] += dp[i - 1][1];
                    dp[i][j] += dp[i - 1][5];
                    dp[i][j] += dp[i - 1][7];
                    break;
                case 5:
                    dp[i][j] += dp[i - 1][2];
                    dp[i][j] += dp[i - 1][4];
                    dp[i][j] += dp[i - 1][6];
                    dp[i][j] += dp[i - 1][8];
                    break;
                case 6:
                    dp[i][j] += dp[i - 1][3];
                    dp[i][j] += dp[i - 1][5];
                    dp[i][j] += dp[i - 1][9];
                    break;
                case 7:
                    dp[i][j] += dp[i - 1][4];
                    dp[i][j] += dp[i - 1][8];
                    break;
                case 8:
                    dp[i][j] += dp[i - 1][5];
                    dp[i][j] += dp[i - 1][7];
                    dp[i][j] += dp[i - 1][9];
                    dp[i][j] += dp[i - 1][0];
                    break;
                case 9:
                    dp[i][j] += dp[i - 1][6];
                    dp[i][j] += dp[i - 1][8];
                    break;
                }
            }
        }

        return (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5] + dp[n][6] + dp[n][7] + dp[n][8] + dp[n][9]);
    }
};

// { Driver Code Starts.
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
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}
// } Driver Code Ends