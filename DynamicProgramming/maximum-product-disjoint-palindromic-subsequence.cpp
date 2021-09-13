#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lps(string s)
    {

        int l, i, j, n = s.size();
        int dp[n][n];

        memset(dp, 0, sizeof(dp));

        for (l = 1; l <= n; l++)
        {
            for (i = 0; i < n - l + 1; i++)
            {
                j = i + l - 1;
                if (i == j)
                {
                    dp[i][j] = 1;
                }
                else if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }

    int maxProduct(string s)
    {

        int ans = 0;
        int i, j, n = s.size(), ns = (1 << n);
        string x, y;

        for (i = 1; i < ns - 1; i++)
        {
            x = "";
            y = "";
            for (j = 0; j < n; j++)
            {
                if ((1 << j) & i)
                {
                    x += s[j];
                }
                else
                {
                    y += s[j];
                }
            }

            ans = max(lps(x) * lps(y), ans);
        }

        return ans;
    }
};