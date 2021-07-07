// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int a[], int n) 
{
    
    int dp[n][n];
    memset(dp, -1, sizeof(dp));
    
    int i, j, l;
    for(i=0; i<n; i++)
    {
        dp[i][i] = a[i];
    }
    
    for(i=0; i<n-1; i++)
    {
        dp[i][i+1] = max(a[i], a[i+1]);
    }
    
    for(l = 3; l <= n; l++)
    {
        for(i = 0; i+l-1 < n; i++)
        {
            dp[i][i+l-1] = max(a[i] + min(dp[i+1][i+l-2], dp[i+2][i+l-1]), 
                                a[i+l-1] + min(dp[i][i+l-3], dp[i+1][i+l-2]));
        }
    }
    
    return dp[0][n-1];
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
