// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int sb(int a[], int n, int x)
    {
        int i = 0, sum = 0, ans = n, j;

        for (j = i; j < n; j++)
        {
            if (a[i] > x)
                return 1;

            sum += a[j];

            while (sum > x)
            {
                ans = min(ans, j - i + 1);
                sum = sum - a[i];
                i++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.sb(a, n, x) << endl;
    }
    return 0;
} // } Driver Code Ends