// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m)
    {

        // sort(a, a + n);

        int i, j, l = 1, r=0, mid, s, ans = INT_MAX;
        for (i = 0; i < n; i++)
            r += a[i];

        // cout << l << " " << r << endl;
        while (l <= r)
        {
            mid = (l + r) / 2;

            i = 0;
            s = 0;
            j = m;
            ans = 0;
            cout << mid << " mid " << endl;
            while (i < n)
            {
                if (s >= mid)
                {
                    j--;
                    s = 0;
                    if (j <= 0)
                        break;

                    i--;
                }
                else
                {
                    s += a[i];
                }

                i++;
            }
            if (j <= 0)
            {
                cout << "in l" << endl;
                ans = mid;
                l = mid + 1;
            }
            else
            {
                cout << "in r" << endl;
                r = mid - 1;
            }

            cout << ans << endl;
        }

        return min(ans, mid);
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
