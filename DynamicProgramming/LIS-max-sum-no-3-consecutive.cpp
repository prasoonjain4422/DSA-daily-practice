// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {

        int i, j, ans = 0;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = a[0];
        dp[2] = a[0] + a[1];
        memset(dp, 0, sizeof(dp));

        for (i = 3; i <= n; i++)
        {
            dp[i] = max(dp[i-1], 
                        max(dp[i-2] + a[i-1], dp[i-3] + a[i-2] + a[i-1]));
        }
        
        return dp[n];
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.longestSubsequence(N, A) << endl;
    }
    return 0;
} // } Driver Code Ends