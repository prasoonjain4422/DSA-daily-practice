// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&a)
	{
	    int ans = 0, i;
	    int n = a.size();
	    
	    vector<pair<int, int>> m;
	    
	    for(i=0;i<n;i++)
	    {
	        m.push_back(make_pair(a[i], i));
	    }
	    
	    sort(m.begin(), m.end());
	    
	    vector<bool> vis(n);
	    int cycle, j;
	    for(i=0;i<n;i++)
	    {
	        
	        if(vis[i])
	            continue;
	        
	        cycle = 0;
	        j = i;
	        while(!vis[j])
	        {
	            cycle++;
	            vis[j] = true;
	            j = m[j].second;
	        }
	        
	        if(cycle > 1)
	            ans += cycle-1;
	    }
	    
	    
	    
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends