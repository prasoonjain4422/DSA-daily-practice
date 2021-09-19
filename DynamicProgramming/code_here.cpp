// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
#define N 9
#define n 9
// Size will be NxN

// } Driver Code Ends

unordered_map<string, bool> row, col;
unordered_map<string, bool> sqr;

class Solution
{

public:
    static bool dfs(int grid[N][N])
    {

        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    break;
            }

            if (j < n)
                break;
        }

        if (i >= n)
            return true;

        int k = 1;
        while (k < 10)
        {
            // cout << " gggg " << i << " " << j << " " << k << endl;
            // if (row[to_string(i) + to_string(k)])
            //     cout << "r" << endl;

            if ((!row[to_string(i) + to_string(k)]) && (!col[to_string(j) + to_string(k)]) && (!sqr[to_string(i / 3) + to_string(j / 3) + to_string(k)]))
            {
                // cout << " in" << endl;
                row[to_string(i) + to_string(k)] = true;
                col[to_string(j) + to_string(k)] = true;
                sqr[to_string(i / 3) + to_string(j / 3) + to_string(k)] = true;

                grid[i][j] = k;

                if (dfs(grid))
                {
                    // cout << i << " " << j << " " << k << endl;
                    return true;
                }

                grid[i][j] = 0;
                row[to_string(i) + to_string(k)] = false;
                col[to_string(j) + to_string(k)] = false;
                sqr[to_string(i / 3) + to_string(j / 3) + to_string(k)] = false;
            }

            k++;
        }

        return false;
    }

    bool SolveSudoku(int grid[N][N])
    {

        int i, j;

        row.clear();
        col.clear();
        sqr.clear();

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    row[to_string(i) + to_string(grid[i][j])] = true;
                    col[to_string(j) + to_string(grid[i][j])] = true;
                    sqr[to_string(i / 3) + to_string(j / 3) + to_string(grid[i][j])] = true;
                }
            }
        }

        if (dfs(grid))
            return true;

        return false;
    }

    //Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        int i, j;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
        }

        char a = 1+48;
        char b = 'b';

        string s = "";
        s += a;
        s += b;
        s += 3+48;
        cout << a << b << endl;
        // cout << (a + b);
        cout << s;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
} // } Driver Code Ends