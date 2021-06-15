// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

const int M = 1000000007;
long long int dp[1000][1000];
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string &s, int i, int j)
    {
    
        if (i == j)
        {
            return 1;
        }
    
        if (i > j)
        {
            return 0;
        }
    
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
    
        if (s[i] == s[j])
        {
            dp[i][j] = (countPS(s, i + 1, j) + countPS(s, i, j - 1) + 1 + M)%M;
        }
        else
        {
            dp[i][j] = (countPS(s, i + 1, j) + countPS(s, i, j - 1) - countPS(s, i + 1, j - 1) + M)%M;
        }
    
        return (dp[i][j]);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        memset(dp, -1, sizeof(dp));
        Solution ob;
        long long int ans = ob.countPS(str, 0, str.length() - 1);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends