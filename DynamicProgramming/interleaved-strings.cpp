// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
    // static bool fun(string &a, string &b, string &c, int i, int j, int k)
    // {
        
    //     if((i>=a.size())&&(j>=b.size()))
    //         return true;
        
    //     if((i<a.size())&&(a[i] == c[k]))
    //     {
    //         if(fun(a, b, c, i+1, j, k+1))
    //             return true;
    //     }
        
    //     if((j<b.size())&&(b[j] == c[k]))
    //     {
    //         if(fun(a, b, c, i, j+1, k+1))
    //             return true;
    //     }
        
    //     return false;
    // }
    
    
    bool isInterleave(string a, string b, string c) 
    {
        // return fun(a, b, c, 0, 0, 0);
        int i, j, k, n, m;
        
        n = a.length();
        m = b.length();
        k = c.length();
        
        if((n + m) != k)
            return false;
        
        
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=m; j++)
            {
                k = i+j;
                if(i==0 && j==0)
                {
                    dp[i][j] = true;
                }
                else if(i==0)
                {
                    if(b[j-1] == c[k-1])
                        dp[i][j] = dp[i][j-1];
                }
                else if(j==0)
                {
                    if(a[i-1] == c[k-1])
                        dp[i][j] = dp[i-1][j];
                }
                else
                {
                    if((a[i-1] == c[k-1])&&(b[j-1] == c[k-1]))
                    {
                        dp[i][j] = dp[i-1][j] | dp[i][j-1];
                    }
                    else if(a[i-1] == c[k-1])
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    else if(b[j-1] == c[k-1])
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        
        return dp[n][m];
    }
    
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends