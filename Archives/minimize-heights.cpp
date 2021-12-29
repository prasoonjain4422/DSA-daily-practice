#include <bits/stdc++.h>
using namespace std;

// brute force will be finding all (2^n) the 
// possible arrays and find the minimum difference

class Solution
{
public:
    vector<int> minimizeDif(int a[], int n, int k)
    {
        
        
        // **********Not Completed**********
        
        
        
        sort(a, a + n);

        // a[0]   - smallest
        // a[n-1] - largest
        vector<int> ans(n);

        if (abs((a[0] + k) - (a[n - 1] - k)) > abs((a[0]) - (a[n - 1])))
        {
            for (int i = 0; i < n; i++)
            {
                ans[i] = a[i] + k;
            }

            return ans;
        }
        else
        {
            vector<int> inc(n), dec(n);
            for (int i = 0; i < n; i++)
            {
                inc[i] = a[i] + k;
                dec[i] = a[i] - k;
            }

            for (int i = 0; i < n; i++)
                cout << inc[i] << " ";

            cout << endl;
            for (int i = 0; i < n; i++)
                cout << dec[i] << " ";

            cout << endl;
            // assuming inc array as answer
            for (int i = 0; i < n; i++)
            {
                ans[i] = inc[i];
            }

            int difference = inc[n - 1] - inc[0];

            for (int i = n - 1; i > 0; i--)
            {

                int newDifference = abs(max(dec[i], ans[i - 1]) - ans[0]);
                if (newDifference < difference)
                {
                    ans[i] = dec[i];
                    difference = newDifference;
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t, k;
    cin >> t;

    Solution obj;
    while (t--)
    {
        int n, i;
        cin >> n >> k;

        int a[n];

        for (auto &x : a)
            cin >> x;

        vector<int> ans = obj.minimizeDif(a, n, k);

        for (auto &x : ans)
            cout << x << " ";
    }

    return 0;
}
