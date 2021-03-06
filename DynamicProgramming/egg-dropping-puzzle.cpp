// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



int dp[201][201];
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int f = 1;
    int eggDrop(int n, int k) 
    {
        
        if ((k == 1) || (k == 0) || (n == 1))
        {
            return k;
        }
        
        if(dp[n][k] != -1)
            return dp[n][k];

        int i, j;

        dp[n][k] = INT_MAX;
        for (j = 2; j <= k; j++)
        {
            dp[n][k] = min(dp[n][k],
                           (max(eggDrop(n - 1, j - 1), eggDrop(n, k - j)) + 1));
            // cout <<k<<" "<< j << " " << dp[n][k] << endl;
        }

        return dp[n][k];
        
        
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
memset(dp, -1, sizeof(dp));
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
