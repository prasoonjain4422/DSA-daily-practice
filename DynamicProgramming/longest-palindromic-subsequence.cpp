// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//largest palindromic subsequence

int lps(string s)
{

    string s2 = s;
    reverse(s2.begin(), s2.end());
    int i, j, ans = 0, n = s.length();
    int dp[n + 1];
    int se[n + 1];
    memset(dp, 1, sizeof(dp));

    for (i = 1; i <= n; i++)
    {
        for (j = i - 1; j >= 0; j--)
        {

            if (s[i - 1] == s2[j - 1])
            {
                dp[i] = dp[i - 1] + 1;
                break;
            }
        }
        if (j < 0)
        {
            dp[i] = dp[i - 1];
        }
    }

    return (dp[n]);
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
        getline(cin, s);
        cout << lps(s) << endl;
    }
    return 0;
}
