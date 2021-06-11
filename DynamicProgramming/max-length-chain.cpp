// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/

bool cmp(struct val a, struct val b)
{
    if(a.second != b.second)
    {
        return (a.second < b.second);
    }
    else
    {
        return (a.first < b.first);
    }
}

int maxChainLen(struct val p[],int n)
{
    
    int i, j;
    sort(p, p+n, cmp);

    i = 0;
    int ans = 1;
    for(j=1; j<n; j++)
    {
        if(p[j].first > p[i].second)
        {
            i = j;
            ans++;
        }
    }
    
    return ans;
}
