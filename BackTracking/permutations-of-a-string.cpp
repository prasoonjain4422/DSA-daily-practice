// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    
	    static void permute(string s, vector<string> &ans, string cur)
	    {
	        
	        if(s.length() == 0)
	        {
	            ans.push_back(cur);
	            return;
	        }
	        
	        int j;
	        for(j=0; j<s.size()-1; j++)
	        {
	            permute(s.substr(0, j) + s.substr(j+1), ans, cur + s[j]);
	        }
	        
            permute(s.substr(0, j), ans, cur + s[j]);
	    }
	    
	    
		vector<string>find_permutation(string s)
		{
		    
		    int i, j, n = s.length();
		    vector<string> ans;

		    permute(s, ans, "");
		    
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends