// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to count subarrays with sum equal to 0
    ll findSubarray(vector<ll> a, int n, int sum)
    {

        ll i, ans = 0, s = 0;
        map<int, int> mm;

        mm[0] = 1;
        for (i = 0; i < n; i++)
        {
            s += a[i];
            if (mm[s - sum] > 0)
            {
                ans += mm[s-sum];
                // cout << ans << " " << i << endl;
            }
            mm[s]++;
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

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n; //input size of array
        cin >> s;
        
        vector<ll> arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr, n, s) << "\n";
    }
    return 0;
} // } Driver Code Ends