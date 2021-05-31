class Solution {
public:
    
    
    void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis)
    {
        
        if(vis[i])
            return;
        
        vis[i] = true;
        for(auto x: adj[i])
        {
            dfs(x, adj, vis);
        }
        
    }
    
    
    int makeConnected(int n, vector<vector<int>>& con)
    {
        int e = con.size();
        
        if(e < n-1)
            return -1;
        
        int i, j, k;
        vector<vector<int>> adj(n);
        vector<bool> vis(n);
        
        for(auto x: con)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);            
        }
        
        int c=0;
        for(i=0; i<n; i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(i, adj, vis);
            }
        }
        
        return c-1;
    }
};