	   	

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    
    bool dfs(int i, bool recStack[], bool vis[], vector<int> adj[])
    {
        
        if(!vis[i])
        {
            recStack[i] = true;
            vis[i] = true;
            int k;
            for(int j=0; j<adj[i].size(); j++)
            {
                
                k = adj[i][j];
                if((!vis[k])&&(dfs(k, recStack, vis, adj)))
                {
                    return true;
                }
                else if(recStack[k])
                {
                    return true;
                }
            }
        }
            
        recStack[i] = false;
        return false;
    }

	bool isCyclic(int V, vector<int> adj[]) 
	{
	    bool recStack[V];
	    bool vis[V];
	    
	    for(int i = 0; i < V; i++)
        {
            vis[i] = false;
            recStack[i] = false;
        }
	    
	    int i;
	    for(i=0; i<V; i++)
	    {
    	    if(dfs(i, recStack, vis, adj))
	        {
	            return true;
	        }
	    }
	    
        return false;
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
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends