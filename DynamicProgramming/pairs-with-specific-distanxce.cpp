// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int a[], int n, int k)
    {
        
        int i, j, ans = 0;
        sort(a, a+n);
        
        for(i=n-1; i>0; i--)
        {
            if((a[i]-a[i-1]) < k)
            {
                ans += a[i] + a[i-1];
                i--;
            }
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends