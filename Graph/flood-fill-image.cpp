class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int x, y;
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();
        bool vis[n][m];
        int i, j;
        
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
                vis[i][j] = false;
        }
        
        q.push({sr, sc});
        
        while(!q.empty())
        {
            
            x = (q.front()).first;
            y = (q.front()).second;
            q.pop();
            
            if(vis[x][y])
                continue;
            
            
            if(((x-1) >= 0)&&(image[x-1][y] == image[x][y]))
            {
                q.push({x-1, y});
            }
            
            if(((x+1) < n)&&(image[x+1][y] == image[x][y]))
            {
                q.push({x+1, y});
            }

            if(((y-1) >= 0)&&(image[x][y-1] == image[x][y]))
            {
                q.push({x, y-1});
            }
            
            if(((y+1) < m)&&(image[x][y+1] == image[x][y]))
            {
                q.push({x, y+1});
            }
            
            image[x][y] = newColor;
            vis[x][y] = true;
        }
        
        return image;
        
    }
};