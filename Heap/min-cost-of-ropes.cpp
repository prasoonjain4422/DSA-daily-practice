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
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long int i, s1, s2;
        
        for(i=0; i<n; i++)
        {
            pq.push(a[i]);
        }
        
        i = 0;
        while(pq.size() != 1)
        {
            
            s1 = pq.top();
            pq.pop();
            s2 = pq.top();
            pq.pop();
            
            i += (s1 + s2);
            pq.push(s1+s2);
        }
        
        return i;
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