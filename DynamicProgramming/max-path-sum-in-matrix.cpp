// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> mat)
    {
        
        int i, j;
        int dp[n+1][n+1];
        
        for(i=1; i<=n; i++)
        {
            dp[n][i] = mat[n-1][i-1];
        }
        
        
        for(i=n-1; i>0; i--)
        {
            for(j=1; j<=n; j++)
            {
                
                dp[i][j] = dp[i+1][j];
                if(j != 1)
                {
                    dp[i][j] = max(dp[i][j], dp[i+1][j-1]);
                }
                
                if(j != n)
                {
                    dp[i][j] = max(dp[i][j], dp[i+1][j+1]);
                }
                
                dp[i][j] += mat[i-1][j-1];
            }
        }
        
        j = 0;
        for(i=1; i<=n; i++)
        {
            j = max(j, dp[1][i]);
        }
        
        return j;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends