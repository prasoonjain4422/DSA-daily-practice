// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[])
	{
	    
	    vector<int> vis(V, -1);
	    
	    
	    queue<int> q;
	    int i;
	    
	    for(int j=0; j<V; j++)
	    {
	        
	        if(vis[j] == -1)
	        {
        	    q.push(j);
        	    vis[j] = 1;
        	    while(!q.empty())
        	    {
        	        i = q.front();
        	        q.pop();
        	        
        	        for(auto x: adj[i])
        	        {
        	            if(vis[x] == -1)
            	            q.push(x);
        
        	            if(vis[x] == vis[i])
        	            {
        	                return false;
        	            }
        	            
            	        vis[x] = 1 - vis[i];
        	        }
        	        
        	    }
	        }
	    }
	    
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends