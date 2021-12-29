
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int matrixMultiplication(int n, int a[])
    {

        int i, j, k, l, ans = 1;
        int dp[n + 1][n + 1];

        for (i = 1; i < n; i++)
        {
            dp[i][i] = 0;
        }

        for (l = 2; l < n; l++)
        {
            for (i = 1; i + l <= n; i++)
            {

                j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
                }
            }
        }

        return dp[1][n - 1];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
} // } Driver Code Ends