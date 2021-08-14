#include <bits/stdc++.h>
using namespace std;

bool cmp(int a[2], int b[2])
{
    return (a[0] < b[0]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, k, x, y, n, m, len, ans = 0;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }


    for (len = 1; len <= n; len++)
    {
        for (i = 0; (i+len) <= n; i++)
        {
            j = i + len - 1;
            
            for(k=0; k<m; k++)
            {
                y = 0;
                for(x=i; x<=j; x++)
                {
                    y += a[x][k];
                }
                
                if(y%2 != 0)
                    break;
            }
            
            if(k==m)
                ans++;
        }
    }

    cout << ans;

    return 0;
}
