// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int i, vector<bool> &vis, stack<int> &s, vector<int> adj[])
	{
	    if(!vis[i])
	    {
	        vis[i] = true;
	        
	        for(auto x: adj[i])
	        {
	            dfs(x, vis, s, adj);
	        }
	        
	        s.push(i);
	    }
	}
	
	
	void dfs2(int i, vector<bool> &vis, vector<int> adj[])
	{
	    if(!vis[i])
	    {
	        vis[i] = true;

	        for(auto x: adj[i])
	        {
	            dfs2(x, vis, adj);
	        }
	    }
	}
	
	
    int kosaraju(int V, vector<int> adj[])
    {
        
        stack<int> s;
        vector<bool> vis(V, false);
        int i;
        for(i=0; i<V; i++)
        {
            if(!vis[i])
                dfs(i, vis, s, adj);
        }
        
        vector<int> adjt[V];
        for(i=0; i<V; i++)
        {
            vis[i] = false;
            for(auto x: adj[i])
            {
                adjt[x].push_back(i);
            }
        }
        
        int ans = 0;
        while(!s.empty())
        {
            i = s.top();
            s.pop();
            
            if(!vis[i])
            {
                ans++;
                dfs2(i, vis, adjt);
            }
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends