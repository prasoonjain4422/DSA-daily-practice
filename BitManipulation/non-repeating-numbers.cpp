// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        
        vector<int> ans(2);
        int ax = 0, i, n = nums.size();
        
        for(i=0; i<n; i++)
        {
            ax = ax^nums[i];
        }
        
        int b = log2(ax);
        ax = ax&(ax-1);
        int o=0, s=0;
        
        for(i=0; i<n; i++)
        {
            if(nums[i]&(1<<b))
            {
                o = o^nums[i];
            }
            else
            {
                s = s^nums[i];
            }
        }
        
        ans[0] = s;
        ans[1] = o;
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends