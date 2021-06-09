// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        
        int  i, j;
        vector<int> dp(y+1, 0);
        vector<int> dp2(y+1, 0);
        int d=0, d2=0;
        
        
        for(i=1; i<=x; i++)
        {
            dp2 = dp;
            for(j=1; j<=y; j++)
            {
                
                if(s1[i-1] == s2[j-1])
                {
                    dp[j] = dp2[j-1] + 1;
                }
                else
                {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                
            }
        }
        
        return dp[y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends