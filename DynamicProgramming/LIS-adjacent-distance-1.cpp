// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        
        int i, j, ans = 0;
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        
        
        for(i=1; i<=n; i++)
        {
            for(j=1; j<i; j++)
            {
                
                if(abs(a[j-1]-a[i-1]) == 1)
                {
                    if(dp[i] < dp[j])
                        dp[i] = dp[j];
                }
            }
            dp[i]++;
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends