// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& a, int n) 
    {
        long long int p=1;
        int i, z=0;
        
        for(i=0;i<n;i++)
        {
            if(a[i] == 0)
                z++;
            else
                p *= a[i];
        }
        
        if(z>1)
        {
            for(i=0;i<n;i++)
            {
                a[i] = 0;
            }
            
            return a;
        }
        
        if(z == 1)
        {
            for(i=0;i<n;i++)
            {
                if(a[i] == 0)
                    a[i] = p;
                else
                    a[i] = 0;
            }
            return a;
        }
        
        for(i=0;i<n;i++)
        {
            if(a[i] == 0)
                a[i] = p;
            else
                a[i] = (long long int)(p/a[i]);
        }
        
        return a;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends