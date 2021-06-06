// { Driver Code Starts
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define N 1000

pair<int,int> findSmallestRange(int arr[][N], int n, int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    rangee = findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

// } Driver Code Ends


// you are required to complete this function 
// function should print the required range
pair<int,int> findSmallestRange(int a[][N], int n, int k)
{
    
    int i, d;
    pair<int, int> mx={0, 0}, it, ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for(i=0; i<k; i++)
    {
        pq.push({a[i][0], i});
        
        if(a[i][0] > mx.first)
        {
            mx = {a[i][0], i};
        }
    }
    
    d = mx.first - (pq.top()).first;
    ans = {(pq.top()).first, mx.first};
    
    vector<int> ind(k, 1);
    while(true)
    {
        
        it = pq.top();
        pq.pop();
        
        if(ind[it.second] < n)
        {
            it.first = a[it.second][ind[it.second]++];
            
            if(it.first > mx.first)
            {
                mx = it;
            }
            
            pq.push(it);
            if(d > (mx.first - (pq.top()).first))
            {
                d = (mx.first - (pq.top()).first);
                ans = {(pq.top()).first, mx.first};
            }
            
        }
        else
        {
            break;
        }
        
    }
    
    return ans;
}