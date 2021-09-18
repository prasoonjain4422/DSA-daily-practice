#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, n, k, d = 0, t;

    cin >> t;
    string s;
    while (t--)
    {
        cin >> n;
        vector<int> a(n), b(n);

        for (i = 0; i < n; i++)
            cin >> a[i];

        unordered_map<int, int> um, vis;

        for (i = 0; i < n; i++)
        {
            cin >> b[i];
            b[i]--;
            um[b[i]] = i;
        }

        int ans = 0, cyc = 0;

        for (i = 0; i < n; i++)
        {
            
            if((vis[i])||(um[a[i]] == j))
                continue;
            
            j = i;
            cyc = 0;
            while (!vis[j])
            {
                vis[j] = true;
                cyc++;
                j = um[a[j]];
            }

            ans += max(0, cyc - 1);
        }

        cout << ans << endl;
    }

    return 0;
}
