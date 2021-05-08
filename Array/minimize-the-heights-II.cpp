// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {

        sort(arr, arr + n);
        int intervals = 1;
        int s[n];
        int b[n];
        int inter;
        int add, sub, i, j, ans = arr[n - 1] - arr[0];
        b[0] = arr[n - 1] - k, s[0] = arr[0] + k;
        if (s[0] > b[0])
            swap(s[0], b[0]);

        for (i = 1; i < n - 1; i++)
        {
            add = arr[i] + k;
            sub = arr[i] - k;

            inter = intervals;
            for (j = 0; j < intervals; j++)
            {
                if ((sub >= s[j]) || (add <= b[j]))
                    continue;

                if (sub >= 0)
                {
                    s[inter] = s[j];
                    s[j] = sub;
                    b[inter] = add;
                    inter++;
                }
                else
                {
                    b[j] = add;
                }
            }
            intervals = inter;
        }

        for (j = 0; j < intervals; j++)
            ans = min(ans, (b[j] - s[j]));

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends