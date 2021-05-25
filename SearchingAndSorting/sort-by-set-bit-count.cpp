// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    int countb(int n)
    {
        int ans = 0;
        while(n!=0)
        {
            ans++;
            n = n&(n-1);
        }
        
        return ans;
    }
    
    void sortBySetBitCount(int a[], int n)
    {
        
        map<int, vector<int>, greater<int>> m;
        
        int i;
        for(i=0; i<n; i++)
        {
            m[countb(a[i])].push_back(a[i]);
        }
        
        i = 0;
        for(auto x: m)
        {
            for(auto y: x.second)
            {
                a[i] = y;
                i++;
            }
        }
        
        return;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
