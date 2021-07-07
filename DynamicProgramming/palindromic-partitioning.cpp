// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int dp[500][500];

    bool isPalin(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    int fun(string &s, int l, int r)
    {


        if (l == r)
        {
            return 0;
        }

        if (dp[l][r] != -1)
        {
            return dp[l][r];
        }

        if (isPalin(s, l, r))
        {
            return dp[l][r] = 0;
        }

        dp[l][r] = INT_MAX;

        for (int i = l; i < r; i++)
        {
            dp[l][r] = min(dp[l][r], fun(s, l, i) + fun(s, i + 1, r));
        }

        dp[l][r]++;
        
        // cout << l << " " << r;
        // cout <<" "<< dp[l][r] << endl;
        
        return dp[l][r];
    }

    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return fun(str, 0, str.length() - 1);
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
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
} // } Driver Code Ends