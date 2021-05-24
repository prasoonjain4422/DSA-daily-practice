// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *a, int n) {
        
        int *ans = new int[2];
        int x = 0, s = 0, i;
        
        for(i=0; i<n; i++)
        {
            a[i] -= 1;
            a[a[i]%n] += n;
        }
        
        for(i=0; i<n; i++)
        {
            if((a[i]/n) == 2)
                ans[0] = i+1;
            
            if((a[i]/n) == 0)
                ans[1] = i+1;
        }
            
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends