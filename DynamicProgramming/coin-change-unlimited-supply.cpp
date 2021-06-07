// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    
    // vector<vector<long long int>> dp = vector<vector<long long int>>(1000, vector<long long int>(1000, -1));
    
    long long int count( int S[], int m, int n)
    {
        long long int dp[n+1][m];
        long long int i, j;
        
        if(n == 0)
            return 1;

        if(n < 0)
            return 0;
        
        for(i=0; i<=m; i++)
        {
            dp[0][i] = 1;
        }
        
        for(i=1; i<=n; i++)
        {
            for(j=0; j<m; j++)
            {
                dp[i][j] = 0;

                if(i-S[j] >= 0)
                {
                    dp[i][j] += dp[i-S[j]][j];
                }
                
                if(j >= 1)
                {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        
        return dp[n][m-1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends