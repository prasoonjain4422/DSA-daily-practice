// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *a, int n) {
	    
    long long int pro = 1, tln = 1, f = 1, ans = 1, i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            pro *= a[i];
            if (f == 1)
                tln *= a[i];
        }
        else if (a[i] < 0)
        {
            ans = max(ans, pro);
            pro *= a[i];
            if (f == 1)
            {
                tln *= a[i];
                f = 0;
            }
        }
        else
        {
            if (pro < 0)
                ans = max(ans, pro / tln);
            else
                ans = max(ans, pro);

            pro = 1;
            tln = 1;
            f = 1;
        }
    }
    if (pro < 0)
        ans = max(ans, pro / tln);
    else
        ans = max(ans, pro);
    
    
	return ans;
	
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends