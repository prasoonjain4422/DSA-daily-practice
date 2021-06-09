// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{
	    
	    int i, j, ans = 0;
	    int dp[n+1];
	    memset(dp, 0, sizeof(dp));

	    
	    for(i=1; i<=n; i++)
	    {
    	    for(j=1; j<i; j++)
	        {
	            if(a[i-1] > a[j-1])
	            {
	                if(dp[i] < dp[j])
	                    dp[i] = dp[j];
	            }
	        }
	        dp[i] += a[i-1];
	        ans = max(ans, dp[i]);
	    }
	    
	    return ans;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends