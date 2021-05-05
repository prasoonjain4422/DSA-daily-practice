// { Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int a[], int n, int k) {
        
        
        int i, ans=0;
        k = n/k;
        unordered_map<int, int> um;
        
        for(i=0;i<n;i++)
        {
            
            if(um[a[i]]>k)
                continue;
            um[a[i]]++;
            if(um[a[i]]>k)
                ans++;
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends