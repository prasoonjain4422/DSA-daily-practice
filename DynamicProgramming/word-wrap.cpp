#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveWordWrap(vector<int>a, int k) 
    {
        int i, j, m, l, n = a.size();
        int dp[n][n];
                
        for(i=0; i<n; i++)
        {
            dp[i][i] = (k-a[i])*(k-a[i]);
        }
        
        for(l=2; l<=n; l++)
        {
            for(i=0; i+l-1<n; i++)
            {
                j = i+l-1;
                
                int sum = 0;
                for(int t=i; t<=j; t++)
                {
                    sum += a[t];
                }
                if(sum+l <= k)
                {
                    dp[i][j] = (k-sum-l)*(k-sum-l);
                }
                else
                {
                    dp[i][j] = INT_MAX;
                }
                
                for(m=i; m<j; m++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j]);
                }
                
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        
        
        
        return dp[0][n-1];
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends