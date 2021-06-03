// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int minSteps(int m, int n, int d)
	{
	    
	    queue<pair<pair<int, int>, int>> q;
	    q.push({{0, 0}, 0});
	    int f, s, ans;
	    
	    bool vis[102][102];
	    memset(vis, false, sizeof(vis));
	    
	    while(!q.empty())
	    {
	        
	        f = (q.front()).first.first;
	        s = (q.front()).first.second;
	        ans = (q.front()).second;
	        q.pop();
	        
	        
	        if(!vis[f][s])
	        {
	                
        	        vis[f][s] = true;
        	        
        	        if((f == d)||(s == d))
        	        {
        	            return ans;
        	        }
        
        	        if((f > m)||(s > n)||(f < 0)||(s < 0))
        	            continue;
	        
        	        
        	        if((f != m)&&(!vis[m][s]))
        	        {
        	            q.push({{m, s}, ans+1});
        	        }
        
        	        if((f != 0)&&(!vis[0][s]))
        	        {
        	            q.push({{0, s}, ans+1});
        	        }
        
        	        if((s != n)&&(!vis[f][n]))
        	        {
        	            q.push({{f, n}, ans+1});
        	        }
        
        	        if((s != 0)&&(!vis[f][0]))
        	        {
        	            q.push({{f, 0}, ans+1});
        	        }
        	        
        	        if((f != 0)&&(s != n)&&(!vis[f-min(f, n-s)][s+min(f, n-s)]))
        	        {
            	        q.push({{f-min(f, n-s), s+min(f, n-s)}, ans+1});
        	        }
        	            
        	        if((s != 0)&&(f != m)&&(!vis[f+min(s, m-f)][s-min(s, m-f)]))
        	        {
            	        q.push({{f+min(s, m-f), s-min(s, m-f)}, ans+1});
        	        }
	        }
	        
	    }
	    
	    
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends