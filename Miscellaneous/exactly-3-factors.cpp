// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int hasThreePrimeFac(long long n) 
    {
        
        int i, j;
        if(n == 1)
            return 0;
        
        i = sqrt(n);
        if(i*i == n)
        {
            for(j = 2; j<i; j++)
            {
                if(n%j == 0)
                    return 0;
            }
            return 1;
        }
        else
        {
            return 0;
        }
        
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.hasThreePrimeFac(N) << endl;
    }
    return 0;
}  // } Driver Code Endsz