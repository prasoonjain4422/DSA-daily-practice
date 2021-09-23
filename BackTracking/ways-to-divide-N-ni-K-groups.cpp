#include <bits/stdc++.h>
using namespace std;

long dfs(int n, int g, int i)
{

    if ((g == 0) && (n == 0))
        return 1;

    if (g <= 0)
        return 0;

    if (n <= 0)
        return 0;

    // cout << n << " " << g << endl;
    long ans = 0;
    for (i; i <= (n - g + 1); i++)
    {
        ans += dfs(n - i, g - 1, i);
        // cout << n << " " << g << " ";
        // cout << "i" << i << " -->" << ans << endl;
    }

    // cout << n << " " << g << " " << ans << "  anssssssssss" << endl;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, g;
    cin >> n >> g;
    cout << dfs(n, g, 1);
    return 0;
}
