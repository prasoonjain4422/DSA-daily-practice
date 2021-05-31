// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        
        int n =grid.size();
        int m =grid[0].size();
        int i, j, x, y;
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        
        int c = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if((grid[i][j] == '1')&&(!vis[i][j]))
                {

                    c++;
                    // cout<<i<<" "<<j<<endl;
                    vis[i][j] = true;
                    q.push({i, j});
                    while(!q.empty())
                    {
                        
                        x = (q.front()).first;
                        y = (q.front()).second;
                        q.pop();
                        
                        if((x>0)&&(y>0)&&(grid[x-1][y-1] == '1')&&(!vis[x-1][y-1]))
                        {
                            vis[x-1][y-1] = true;
                            q.push({x-1, y-1});
                        }

                        if((x>0)&&(grid[x-1][y] == '1')&&(!vis[x-1][y]))
                        {
                            vis[x-1][y] = true;
                            q.push({x-1, y});
                        }

                        if((x>0)&&(y<(m-1))&&(grid[x-1][y+1] == '1')&&(!vis[x-1][y+1]))
                        {
                            vis[x-1][y+1] = true;
                            q.push({x-1, y+1});
                        }
                        
                        if((y>0)&&(grid[x][y-1] == '1')&&(!vis[x][y-1]))
                        {
                            vis[x][y-1] = true;
                            q.push({x, y-1});
                        }

                        if((y<(m-1))&&(grid[x][y+1] == '1')&&(!vis[x][y+1]))
                        {
                            vis[x][y+1] = true;
                            q.push({x, y+1});
                        }
                        
                        if((x<(n-1))&&(y>0)&&(grid[x+1][y-1] == '1')&&(!vis[x+1][y-1]))
                        {
                            vis[x+1][y-1] = true;
                            q.push({x+1, y-1});
                        }

                        if((x<(n-1))&&(grid[x+1][y] == '1')&&(!vis[x+1][y]))
                        {
                            vis[x+1][y] = true;
                            q.push({x+1, y});
                        }

                        if((x<(n-1))&&(y<(m-1))&&(grid[x+1][y+1] == '1')&&(!vis[x+1][y+1]))
                        {
                            vis[x+1][y+1] = true;
                            q.push({x+1, y+1});
                        }
                        
                    }
                    
                }
            }
        }
        
        return c;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends