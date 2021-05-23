// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int a[], int n , int x )
{
    
    int i, l=0;
    int r = n-1;
    int m;
    vector<int> ans;
    
    while(l<=r)
    {
        m = (l+r)/2;
        
        if(a[m] < x)
            l = m+1;
        else
        {
            r = m-1;
            i = m;
        }
    }
    
    if(a[i] == x)
        ans.push_back(i);
    else
        ans.push_back(-1);
    
    
    l=0;
    r = n-1;
    while(l<=r)
    {
        m = (l+r)/2;
        
        if(a[m] <= x)
        {
            l = m+1;
            i = m;
        }
        else
            r = m-1;
    }
    
    if(a[i] == x)
        ans.push_back(i);
    else
        ans.push_back(-1);
    
    return ans;
}