// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

int dp[1001][1001];
class Solution
{

public:
    int minimumCost(int cost[], int n, int w)
    {

        if (w == 0)
            return 0;

        if (w < 1)
            return -1;

        int i, j;

        if (dp[n][w] != INT_MAX)
        {
            return dp[n][w];
        }
        
        
        for (i = 1; i <= n; i++)
        {
            if (i > w)
                break;

            if (cost[i - 1] == -1)
                continue;

            j = minimumCost(cost, n, w - i);

            if (j != -1)
            {
                dp[n][w] = min(dp[n][w], j + cost[i - 1]);
            }
        }

        if (dp[n][w] == INT_MAX)
            dp[n][w] = -1;

        // cout << dp[n][w] << " " << n << " " << w << endl;

        return dp[n][w];
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
        int n, w;
        cin >> n >> w;
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=w; j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";
    }
    return 0;
} // } Driver Code Ends