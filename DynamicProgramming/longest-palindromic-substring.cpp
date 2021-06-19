#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
long long int dp[1000][1000];
class Solution
{
public:
    string lpsub(string s)
    {
        int i, j, k, start = 0, len = 1;
        int n = s.length();
        bool dp[n + 1][n + 1];
        memset(dp, false, sizeof(dp));
        

        for (i = 1; i <= n; i++)
        {
            dp[i][i] = true;
        }

        for (i = 1; i <= n; i++)
        {
            if (s[i - 1] == s[i])
            {
                dp[i][i + 1] = true;

                len = 2;
                start = i - 1;
            }
        }

        for (k = 3; k <= n; k++)
        {
            for (i = 1; i <= n - k + 1; i++)
            {
                j = i + k - 1;
                if (j <= n)
                {
                    if ((dp[i + 1][j - 1]) && (s[i - 1] == s[j - 1]))
                    {
                        dp[i][j] = true;

                        if (len < k)
                        {
                            len = k;
                            start = i - 1;
                        }
                    }
                }
            }
        }

        return (s.substr(start, len));
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
        string str;
        cin >> str;
        Solution ob;
        cout << ob.lpsub(str) << endl;
    }
}
