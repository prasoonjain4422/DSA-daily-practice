// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long a[], long long n) 
    {
        
        priority_queue<int> pq;
        long long i, s = 0;
        
        for(i=0; i<n; i++)
        {
            pq.push(a[i]);
        }
        
        s = pq.top();
        pq.pop();
        while(!pq.empty())
        {
            i = pq.top();
            pq.pop();
            
            s += (s + i);
            
        }
        
        
        return s;
    }
};


// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends