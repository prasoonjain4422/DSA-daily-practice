// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
        
        // Kadane's Algo
	    
	    int i, ans = 0, fans = INT_MIN;
	    int n = s.length();
	    
	    for(i=0; i<n; i++)
	    {
	        
	        if(s[i] == '0')
	        {
    	        if(ans < 0)
    	            ans = 0;
    	        
	            ans++;
	        }
	        else
	        {
	            ans--;
	        }
	        
	           
	        if(fans < ans)
    	        fans = ans;
	        
	    }
	    
	    return max(-1, fans);
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends