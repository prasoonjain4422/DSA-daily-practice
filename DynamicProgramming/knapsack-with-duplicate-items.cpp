// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {

        int i, j, k;
        int dp[w + 1];

        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= w; j++)
            {

                if ((i == 0) || (j == 0))
                {
                    dp[j] = 0;
                }
                else
                {

                    dp[j] = dp[j];
                    k = 1;
                    while (true)
                    {
                        if (k * wt[i-1] <= j)
                        {
                            dp[j] = max(dp[j], k * val[i-1] + dp[j - (k * wt[i-1])]);
                        }
                        else
                        {
                            break;
                        }
                        k++;
                    }
                }
            }
        }

        return dp[w];
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
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
} // } Driver Code Ends