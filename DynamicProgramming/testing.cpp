#include <bits/stdc++.h>
using namespace std;

int k, x, y, n, g, len, ans = 0;
int solve(vector<vector<int>> &a, int i, vector<bool> visg)
{
    if (i >= n)
    {
        for (int j = 0; j < g; j++)
        {
            if (!visg[j])
            {
                return INT_MIN;
            }
        }
        return 0;
    }

    int ans = 0, ans2;
    for (int j = 0; j < g; j++)
    {
        visg[j] = true;
        ans2 = solve(a, i + 1, visg) + a[i][j];
        ans = max(ans, ans2);
        visg[j] = false;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j;
    cin >> n >> g;

    vector<vector<int>> a(n, vector<int>(g, 0));
    vector<bool> visg(g, false);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < g; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << solve(a, 0, visg);

    return 0;
}
