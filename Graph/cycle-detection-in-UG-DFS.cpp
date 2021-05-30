// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool dfs(int i, int V, vector<int>adj[], int parent, vector<bool> &vis)
    {
        
        vis[i]= true;
        int j;
        
        for(j=0; j<adj[i].size(); j++)
        {
            if(!vis[adj[i][j]])
            {
                if(dfs(adj[i][j], V, adj, i, vis))
                {
                    return true;
                }
            }
            else if(adj[i][j] != parent)
            {
                return true;
            }
            
        }
        
        return false;
    }
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    
	    
	    vector<bool> vis(V);
	    int i;
	    
	    for(i=0; i<V; i++)
	    {
	        if(!vis[i])
	        {
	            if(dfs(i, V, adj, -1, vis))
	                return true;
	            
	        }
	    }
	    
	    
	    return false;
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
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends