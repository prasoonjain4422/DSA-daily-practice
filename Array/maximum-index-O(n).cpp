// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int a[], int n) 
    {
        
        int i, j, ans = 0;
        int l[n], r[n];
        l[0] = a[0];
        r[n-1] = a[n-1];
        for(i=1; i<n; i++)
        {
            l[i] = min(a[i], l[i-1]);
        }
            
        for(i=n-2; i>=0; i--)
        {
            r[i] = max(a[i], r[i+1]);
        }

        i = 0;
        j = 0;
        while(true)
        {
            while(((j+1)<n)&&(l[i]<=r[j+1]))
            {
                j++;
            }
            
            ans = max(ans, j-i);
            
            i += 1;
            while((i<n)&&(l[i] == l[i-1]))
            {
                i++;
            }
            if(i >= n)
                return ans;
        }
        return 0;
    }

};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends