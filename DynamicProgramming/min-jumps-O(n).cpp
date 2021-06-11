// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int a[], int n)
    {
        
        int i, m, ans = 1;
        int step = a[0];
        m = 0;
        
        if(step == 0)
        {
            return -1;
        }
        
        
        for(i=1; i<n-1; i++)
        {
            step--;
            
            m = max(m, i+a[i]);
            
            if(step == 0)
            {
                
                ans++;
                if(m-i <= 0)
                {
                    return -1;
                }
                    
                step = m-i;
                m = 0;
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends