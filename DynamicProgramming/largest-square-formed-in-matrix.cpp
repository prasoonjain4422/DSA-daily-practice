        
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        
        int i, j, ans = 0;
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        
        
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if((i==0)||(j==0))
                {
                    dp[i][j] = mat[i][j];
                    ans = max(ans, dp[i][j]);
                }
                else if(mat[i][j] == 1)
                {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    ans = max(ans, dp[i][j]);
                }
                
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends