// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//largest palindromic subsequence

int dp[1000][1000];

int lps(string s, int i, int j)
{

    if (i == j)
    {
        return 1;
    }
    
    if (i > j)
    {
        return 0;
    }
    
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == s[j])
    {
        dp[i][j] = lps(s, i + 1, j - 1) + 2;
    }
    else
    {
        dp[i][j] = max(lps(s, i + 1, j), lps(s, i, j - 1));
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
        getline(cin, s);
        cout << lps(s, 0, s.length() - 1) << endl;
    }
    return 0;
}
