// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long countTriplets(long long a[], int n, long long sum)
    {
        sort(a, a + n);

        long long i, j, k, ans = 0;
        for (i = 0; i < n - 2; i++)
        {
            j = i + 1;
            k = n - 1;

            while (j < k)
            {
                if (a[i] + a[j] + a[k] >= sum)
                {
                    k--;
                }
                else
                {
                    ans += k - j;
                    j++;
                }
            }
        }

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
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(arr, n, sum);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends