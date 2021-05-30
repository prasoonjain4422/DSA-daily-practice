// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    
	    
	    vector<bool> vis(V);
	    queue<pair<int, int>> q;
	    int i, k;
	    pair<int, int> j;
	    
	    for(i=0; i<V; i++)
	    {
	        if(!vis[i])
	        {
        	    q.push(make_pair(i, -1));
        	    
        	    while(!q.empty())
        	    {
        	        
        	        j = q.front();
        	        q.pop();
        	        vis[j.first] = true;
        	        
        	        for(k=0; k<adj[j.first].size(); k++)
        	        {
        	            if(!vis[adj[j.first][k]])
        	            {
        	                q.push(make_pair(adj[j.first][k], j.first));
        	            }
        	            else if(adj[j.first][k] != j.second)
        	            {
        	                return true;
        	            }
        	        }
        	    }
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