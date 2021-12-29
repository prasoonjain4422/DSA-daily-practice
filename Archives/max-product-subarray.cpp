#include <bits/stdc++.h>
using namespace std;

// brute force will be finding all subarray's
// product and print maximum product

class Solution
{
public:
    int maxProduct(int a[], int n)
    {
        int maxPro = 1;
        int currPro = 1;
        int tillFirstNegative = 1;
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                currPro = currPro * a[i];
                maxPro = max(maxPro, currPro);
            }
            else if (a[i] < 0)
            {

                currPro = currPro * a[i];
                if (flag == 0)
                {
                    flag = 1;
                    tillFirstNegative = currPro;
                }

                maxPro = max(maxPro, currPro);
            }
            else
            {
                maxPro = max(maxPro, currPro / tillFirstNegative);
                currPro = 1;
            }
        }

        maxPro = max(maxPro, currPro / tillFirstNegative);

        return maxPro;
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
        cin >> n;
        // cout << n;

        int a[n];

        for (auto &x : a)
            cin >> x;

        cout << obj.maxProduct(a, n);
    }

    return 0;
}
