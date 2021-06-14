#include <bits/stdc++.h>
using namespace std;

//largest palindromic subsequence

int dp[1000][1000];
int ans;

int lps(string s, int i, int j)
{

    if (i == j)
    {
        // ans += 1;
        return 0;
    }

    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == s[j])
    {
        int l = lps(s, i + 1, j - 1);
        
        if(l == 1)
        {
            dp[i][j] = (j - i - 1) + 1;        
        }
        else
        {
            dp[i][j] = (j - i - 1) + (l + 1);
        }

        ans += dp[i][j];
        cout << ans << endl;
    }
    else
    {
        dp[i][j] = max(lps(s, i + 1, j), lps(s, i, j - 1));
        // ans += dp[i][j];
    }

    return (dp[i][j]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        memset(dp, -1, sizeof(dp));
        ans = 0;
        getline(cin, s);
        int n = 0;
        n = s.length();
        lps(s, 0, s.length() - 1);
        cout << "ans = " << ans + n << endl;
    }
    return 0;
}
