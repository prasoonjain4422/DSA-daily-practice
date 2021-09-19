#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int dfs(vector<bool> vis, int k, int n)
{
    
    int i 
    
        
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, k, n, t;

    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<bool> vis(n, false);
        int ans2 = 0;

        for (i = 0; i < n; i++)
        {
            
            vis[i] = true;
            k = dfs(vis, i, n);
            
            for(j = 0; j<n; j++)
            {
                if(!vis[j])
                    break;
            }
            
            if(j<n)
                ans2 = min(ans2, k);
            
            
        }

        cout << ans2 << endl;
    }

    return 0;
}
