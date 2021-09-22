#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  
    static bool check(int a[], int n, vector<bool> &vis, int sum, int i)
    {
        
        // cout<<sum<<endl;
        if(sum == 0)
            return true;
            
        if(sum < 0)
            return false;
        
        for(i; i<n; i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                if(check(a, n, vis, sum-a[i], i+1))
                    return true;

                vis[i] = false;
            }
        }
        return false;
    }
  
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
        
        int i, j, sum = 0, ss;
        
        for(i=0; i<n; i++)
            sum += a[i];
        
        if(sum % k != 0)
            return false;
        
        ss = sum / k;
        
        sort(a, a+n, greater<int>());
        vector<bool> vis(n, false);
        
        for(i=0; i<k; i++)
        {
            // cout<<i<<endl;
            
            if(!check(a, n, vis, sum/k, 0))
                return false;
            
            // for(int j=0; j<n; j++)
            //     cout<<vis[j]<<" ";
            // cout<<endl;
            
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends