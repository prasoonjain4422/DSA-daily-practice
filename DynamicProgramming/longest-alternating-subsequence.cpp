// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int AlternatingaMaxLength(vector<int> &a)
    {

        int i, j, k, len = 2, n = a.size();

        if ((n == 1) || (n == 2))
        {
            return n;
        }

        int dp[n];
        int ad[n];
        memset(dp, 0, sizeof(dp));
        memset(ad, 0, sizeof(ad));
        dp[0] = 1;
        dp[1] = 2;
        if (a[0] > a[1])
        {
            ad[1] = 1;
        }
        else
        {
            ad[1] = -1;
        }


        for (i = 2; i < n; i++)
        {
            dp[i] = 1;
            ad[i] = 0;
            for (j = i - 1; j >= 0; j--)
            {

                if (ad[j] == 0)
                {
                    dp[i] = 2;
                    if (a[j] > a[i])
                    {
                        ad[i] = 1;
                    }
                    else
                    {
                        ad[i] = -1;
                    }
                }
                else if ((ad[j] == 1) && (a[j] < a[i]))
                {
                    if (dp[i] < dp[j])
                    {
                        dp[i] = dp[j];
                        ad[i] = -1;
                    }
                }
                else if ((ad[j] == -1) && (a[j] > a[i]))
                {
                    if (dp[i] < dp[j])
                    {
                        dp[i] = dp[j];
                        ad[i] = 1;
                    }
                }
            }
            dp[i]++;
            cout << i << " " << dp[i] << endl;

            if (len < dp[i])
                len = dp[i];
        }

        return len;
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.AlternatingaMaxLength(nums);
        cout << ans << "\n";
    }
    return 0;
}
