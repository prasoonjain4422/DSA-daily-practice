class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n = board.size();
        
        vector<bool> vis(n*n + 1, false);
        int i, m;
        
        queue<pair<int, int>> q;
        q.push({1, 0});
        
        while(!q.empty())
        {
            i = (q.front()).first;
            m = (q.front()).second;
            q.pop();
            
            if((n-1 - (i-1)/n) % 2 == 0)
            {
                if(n%2 == 0)
                {
                    if(board[n-1 - (i-1)/n][n-1 - (i-1)%n] != -1)
                    {
                        i = board[n-1 - (i-1)/n][n-1 - (i-1)%n];
                    }
                }
                else
                {
                    if(board[n-1 - (i-1)/n][(i-1)%n] != -1)
                    {
                        i = board[n-1 - (i-1)/n][(i-1)%n];
                    }
                }
            }
            else
            {
                if(n%2 == 0)
                {
                    if(board[n-1 - (i-1)/n][(i-1)%n] != -1)
                    {
                        i = board[n-1 - (i-1)/n][(i-1)%n];
                    }
                }
                else
                {
                    if(board[n-1 - (i-1)/n][n-1 - (i-1)%n] != -1)
                    {
                        i = board[n-1 - (i-1)/n][n-1 - (i-1)%n];
                    }
                }

                    
            }
            
            if(i == n*n)
            {
                return m;
            }
            
            if(vis[i] == true)
            {
                continue;
            }
            
            vis[i] = true;
            // cout<<i<<endl;
            
            if((i+1)<=(n*n))
            {
                q.push({i+1, m+1});
            }
            
            if((i+2)<=(n*n))
            {
                q.push({i+2, m+1});
            }
            
            if((i+3)<=(n*n))
            {
                q.push({i+3, m+1});
            }
            
            if((i+4)<=(n*n))
            {
                q.push({i+4, m+1});
            }
            
            if((i+5)<=(n*n))
            {
                q.push({i+5, m+1});
            }
            
            if((i+6)<=(n*n))
            {
                q.push({i+6, m+1});
            }
        }
        
        return -1;
    }
};