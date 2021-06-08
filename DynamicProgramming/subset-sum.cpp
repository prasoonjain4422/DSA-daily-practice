// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int a[])
    {
        
        int i, j, sum=0;
        for(i=0; i<n; i++)
        {
            sum += a[i];
        }
        
        if(sum % 2 != 0)
        {
            return 0;
        }
        
        sum = sum/2;
        bool dp[sum+1][n+1];
        // int dp[sum+1][n+1];
        memset(dp, false, sizeof(dp));
        // memset(dp, 0, sizeof(dp));
        
        for(i=0; i<=n; i++)
        {
            dp[0][i] = true;
            // dp[0][i] = 1;
        }
        
        for(i=1; i<=sum; i++)
        {
            dp[i][0] = false;
            // dp[i][0] = 0;
        }
        
        for(i=1; i<=sum; i++)
        {
            for(j=1; j<=n; j++)
            {
                dp[i][j] = dp[i][j-1];
                if(i >= a[j-1])
                {
                    dp[i][j] = dp[i][j] || dp[i-a[j-1]][j-1];
                }
            }
        }
        
        if(dp[sum][n])
            return 1;
        else
            return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends