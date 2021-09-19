
#include<bits/stdc++.h>
#define n 9
using namespace std;



unordered_map<string, bool> row, col;
unordered_map<string, bool> sqr;

class Solution {
public:
    
    
    static bool dfs(vector<vector<char>>& grid)
    {
        
        int i, j;
        string tr, tc, ts;

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(grid[i][j] == '.')
                    break;
            }
            if (j < n)
                break;
        }
        
        if(i >= n)
            return true;
        
        int k = 1;
        while (k < 10)
        {
            
                tr = "";
                tr += i +48;
                tr += (k+48);

                tc = "";
                tc += j +48;
                tc += (k+48);    

                ts = "";
                ts += i/3 +48;
                ts += j/3 +48;
                ts += (k+48);   
            
            
            
            if ((!row[tr]) && (!col[tc]) && (!sqr[ts]))
            {
                // cout << " in" << endl;
                
                row[tr] = true;
                col[tc] = true;
                sqr[ts] = true;

                grid[i][j] = (k+48);

                if (dfs(grid))
                {
                    // cout << i << " " << j << " " << k << endl;
                    return true;
                }

                grid[i][j] = '.';
                row[tr] = false;
                col[tc] = false;
                sqr[ts] = false;
            }
            
            k++;
        }

        return false;
    }
    
    
    
    void solveSudoku(vector<vector<char>>& grid) 
    {
        
        int i, j;

        row.clear();
        col.clear();
        sqr.clear();
        string tr, tc, ts;
        
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (grid[i][j] != '.')
                {
                    tr = "";
                    tr += i+48;
                    tr += grid[i][j];
                    row[tr] = true;

                    tc = "";
                    tc += j+48;
                    tc += grid[i][j];                    
                    col[tc] = true;

                    ts = "";
                    ts += i/3 +48;
                    ts += j/3 +48;
                    ts += grid[i][j];                    
                    sqr[ts] = true;
                }
            }
        }

        dfs(grid);
    }
};