// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) 
    {
        int i, j;
        int n = s.size();
        int m = t.size();
        
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        
        for(j=0; j<=m; j++)
        {
            for(i=0; i<=n; i++)
            {
                if(i==0)
                {
                    dp[i][j] = j;
                }
                else if(j==0)
                {
                    dp[i][j] = i;
                }
                else if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min( dp[i-1][j-1], min( dp[i][j-1], dp[i-1][j]));
                }
            }
        }
        
        
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends