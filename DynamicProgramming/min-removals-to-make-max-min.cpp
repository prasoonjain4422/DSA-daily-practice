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
    int minremo1(int a[], int l, int r, int k)
    {

        // O(n^2)

        if (dp[l][r] != -1)
            return dp[l][r];

        if ((a[r] - a[l]) <= k)
        {
            return 0;
        }

        dp[l][r] = min(minremo1(a, l + 1, r, k), minremo1(a, l, r - 1, k)) + 1;

        return dp[l][r];
    }

    int minremo2(int a[], int l, int r, int k)
    {

        // O(n)

        int i, j, ans = INT_MAX;
        int n = r + 1;
        int dp[n + 1];

        dp[0] = 0;

        for (i = 1; i <= n; i++)
        {

            dp[i] = i;
            j = dp[i - 1];
            while ((j != i) && (a[i] - a[j] > k))
            {
                j++;
            }

            dp[i] = min(dp[i], j);
            ans = min(ans, n - i + j - 1);
        }

        return ans;
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
        int n, k;
        cin >> n >> k;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        Solution ob;
        cout << ob.minremo1(a, 0, n - 1, k) << "\n";
        cout << ob.minremo2(a, 0, n - 1, k) << "\n";
    }
    return 0;
} // } Driver Code Ends
