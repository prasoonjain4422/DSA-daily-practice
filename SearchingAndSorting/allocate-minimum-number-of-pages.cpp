// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
        int findPages(int a[], int n, int m)
    {

        int i, j, l = 0, r = 0, mid, s, ans = INT_MAX;
        for (i = 0; i < n; i++)
            r += a[i];

        // cout << l << " " << r << endl;
        while (l <= r)
        {
            mid = (l + r) / 2;

            i = 0;
            s = 0;
            j = m;

            // cout << mid << " mid " << endl;
            while (i < n)
            {
                
                if(a[i] > mid)
                {
                    break;
                }
                

                if ((s + a[i]) > mid)
                {
                    j--;
                    if (j == 0)
                        break;
                    // cout << "j-- " << i << endl;
                    s = a[i];
                }
                else
                {
                    s += a[i];
                }

                i++;
            }
            if (i >= n)
            {
                // cout << "in r" << endl;
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
            {
                // cout << "in l" << endl;
                l = mid + 1;
            }

            // cout << ans << endl;
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends