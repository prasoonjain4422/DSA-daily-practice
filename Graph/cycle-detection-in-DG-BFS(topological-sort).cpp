// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	
	   	queue<int> q;
	   	int k, j, i;
	   	
	   	unordered_map<int, int> indeg(V);
	   	for(k=0; k<V; k++)
	   	{
	   	    for(j=0; j<adj[k].size(); j++)
	   	    {
    	   	    indeg[adj[k][j]]++;
	   	    }
	   	}
	   	
	   	for(k=0; k<V; k++)
	   	{
	   	    if(indeg[k] == 0)
	   	        q.push(k);
	   	}
	   	
	   	int v = 0;

	   	while(!q.empty())
	   	{
	   	    i = q.front();
	   	    q.pop();
            v++;
	   	    
	   	    for(j=0; j<adj[i].size(); j++)
	   	    {
	   	        indeg[adj[i][j]]--;
	   	        if(indeg[adj[i][j]] == 0)
	   	        {
	   	            q.push(adj[i][j]);
	   	        }
	   	        
	   	    }
	   	}
	   	
	   	if(v<V)
   	        return true;
   	    
   	    
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