// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

    //largest palindromic subsequence

int lps(string s)
{
    
    int i, j, ans = 0, n = s.length();
    int dp[n+1];
    int se[n+1];
    memset(dp, 0, sizeof(dp));
    
    for(i=2; i<=n; i++)
    {
        for(j = 1; ; j++)
        {
            if(dp[i-1] > 0)
            {
                if(s[i-1] == s[i-1-j-2*dp[i-1]])
                {
                    dp[i] = dp[i-1] + 1;
                }
                else
                {
                    dp[i] = dp[i-1];
                }
            }
            else
            {
                if(s[i-1] == s[i-2])
                {
                    dp[i] = 1;
                }
            }
            
        }
        
        ans = max(ans, dp[i]);
    }
    
    return (2*ans);
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
