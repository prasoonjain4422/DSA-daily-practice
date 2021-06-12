// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
	long long int table[n+1], i, j;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	int a[] = {3, 5, 10};
	
	
	for(j=0; j<=2; j++)
	{
    	for(i=1; i<=n; i++)
    	{
    	    if(i >= a[j])
    	    {
    	        table[i] += table[i-a[j]];
    	    }
    	}
	}
	
	return table[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends