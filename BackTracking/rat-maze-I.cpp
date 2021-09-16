// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void dfs(vector<vector<int>> &m, int n, vector<vector<bool>> &vis, int a, int b, string c, vector<string> &ans)
    {
        
        if((a == n-1)&&(b == n-1))
        {
            ans.push_back(c);
            return;
        }
        
        vis[a][b] = true;
        
        if((a+1<n)&&(!vis[a+1][b])&&(m[a+1][b] == 1))
        {
            dfs(m, n, vis, a+1, b, c+"D", ans);
        }
        
        if((a>0)&&(!vis[a-1][b])&&(m[a-1][b] == 1))
        {
            dfs(m, n, vis, a-1, b, c+"U", ans);
        }
        
        if((b+1<n)&&(!vis[a][b+1])&&(m[a][b+1] == 1))
        {
            dfs(m, n, vis, a, b+1, c+"R", ans);
        }
        
        if((b>0)&&(!vis[a][b-1])&&(m[a][b-1] == 1))
        {
            dfs(m, n, vis, a, b-1, c+"L", ans);
        }
        
        vis[a][b] = false;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(false));

        dfs(m, n, vis, 0, 0, "", ans);
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends