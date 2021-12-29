#include<bits/stdc++.h>
using namespace std;



class Solution
{
    public:
    
    int tailindex(vector<int> &tail, int l, int r, int s)
    {
        
        int m = (l+r)/2;
        
        while(l<=r)
        {
            if(tail[m] <= s)
            {
                l = m+1;
            }
            else
            {
                r = m;
            }
        }
        
        return m;
    }
    
    int longestSubsequence(int n, int a[])
    {
        
        int i, ans=0;
        vector<int> tail(n, 0);
        // int dp[n+1];
        // memset(dp, 0, sizeof(dp));
        // dp[0] = 0;
        // dp[1] = 1;
        tail[0] = a[0];
        int l = 1;
        
        for(i=1; i<n; i++)
        {
            
            if(a[i] > tail[l-1])
            {
                tail[l++] = a[i];
            }
            else if(a[i] < tail[0])
            {
                tail[0] = a[i];
            }
            else
            {
                tail[tailindex(tail, 0, l-1, a[i])] = a[i];
            }
            
            
            // dp[i]++;
            // ans = max(ans, dp[i]);
        }
        
        return l;
    }
};


int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

