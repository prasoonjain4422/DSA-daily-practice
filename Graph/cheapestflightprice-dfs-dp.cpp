class Solution {
public:    
    
    int dfs(int src, int dst, int dp[100][102], vector<pair<int, int>> adj[], int k)
    {
        
        if(k < 0)
            return INT_MAX;
        
        if(dp[src][k] != -1)
            return dp[src][k];
        
        if(src == dst)
            return 0;
        
        int ans = INT_MAX, d;
        for(auto x: adj[src])
        {
            d = dfs(x.first, dst, dp, adj, k-1);
            if(d != INT_MAX)
                ans = min(ans, d + x.second);
        }
        
        dp[src][k] = ans;
        return ans;
    }
    
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        
        int dp[100][102];
        memset(dp, -1, sizeof(dp));
        
        vector<pair<int, int>> adj[n];
        vector<bool> vis(n, false);
        map<pair<int, int>, int> price;
        
        for(auto x: flights)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }
        
        int i, j, m, p, ans = INT_MAX;
        
        ans = dfs(src, dst, dp, adj, k+1);
        
        if(ans == INT_MAX)
        {
            return -1;
        }
        
        return ans;
    }
};