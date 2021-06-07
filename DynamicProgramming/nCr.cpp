// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
const int M = 1000000007;

class Solution{
public:
    int nCr(int n, int r)
    {
        
        // nCr = nC(r-1) + (n-1)C(r-1)
        
        if(r > n)
            return 0;
        
        if(r > (n-r))
            r = (n-r);
        
        
        int i;
        int dp[r+1];
        memset(dp, 0, sizeof(dp));
        
        dp[1] = 1;
        int j = 2;
        while(j <= n)
        {
            for(i = min(j, r); i > 1; i--)
            {
                dp[i] = (dp[i] + dp[i-1])%M;
            }
            
            dp[1] = j;
            j++;
        }
        
        return dp[r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends