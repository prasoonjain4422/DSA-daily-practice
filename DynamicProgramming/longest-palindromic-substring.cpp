#include <bits/stdc++.h>
using namespace std;

string a;
const int M = 1000000007;
long long int dp[1000][1000];
class Solution
{
public:
    string lpsub(string s)
    {
        int i, j;
        int n = s.length();
        bool dp[n + 1][n + 1];
        string ans = "";

        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                if ((i == 0) || (j == 0))
                {
                    dp[i][j] = true;
                }
                else if (i == j)
                {
                    dp[i][j] = true;
                }
                else if (s[i - 1] == s[j - 1])
                {
                    if (j - 1 > i)
                    {
                        dp[i][j] = ((dp[i + 1][j - 1]));
                    }
                    else
                    {
                        dp[i][j] = true;
                    }

                    if (dp[i][j] == true)
                    {
                        if ((j - i + 1) > ans.length())
                        {
                            ans = s.substr(i - 1, j - i - 1);
                        }
                    }
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return ans;
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
        a = "";
        memset(dp, -1, sizeof(dp));
        Solution ob;
        cout << ob.lpsub(str) << endl;
    }
}
