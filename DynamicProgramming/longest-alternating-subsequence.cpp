// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
    int AlternatingaMaxLength(vector<int> &a)
    {

        int inc = 1;
        int dec = 1;
        int i;
        
        
        for(i=1; i<a.size(); i++)
        {
            if(a[i-1] < a[i])
            {
                inc = dec + 1;
            }
            else if(a[i-1] > a[i])
            {
                dec = inc + 1;
            }
        }
        
        
        return max(inc, dec);

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
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends