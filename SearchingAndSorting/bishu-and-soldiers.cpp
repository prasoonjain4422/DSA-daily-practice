#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int i, n, q, j;

    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];

    cin >> q;
    vector<int> p(q);
    for (i = 0; i < q; i++)
        cin >> p[i];

    int m = *max_element(p.begin(), p.end());
    vector<pair<int, int>> ans(m);
    vector<bool> vis(n);
    
    int temp=0;
    ans[0].first = 0;
    for (j = 0; j < n; j++)
    {
        if (a[j] <= 1)
        {
            ans[0].first += a[j];
            temp++;
            vis[j] = true;
        }
    }
    ans[0].second = temp;

    for (i = 1; i < m; i++)
    {
        ans[i].first = ans[i - 1].first;
        ans[i].second = ans[i - 1].second;
        for (j = 0; j < n; j++)
        {
            if (!vis[j])
            {
                if (a[j] <= i + 1)
                {
                    ans[i].first += a[j];
                    ans[i].second++;
                    vis[j] = true;
                }
            }
        }
    }

    for (i = 0; i < q; i++)
    {
        cout << ans[p[i]-1].second << " " << ans[p[i]-1].first << endl;
    }

    return 0;
}
