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

    int t, n, c, i, j, s, ans, ans2;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        vector<int> x(n), d(n - 1);

        for (i = 0; i < n; i++)
            cin >> x[i];

        sort(x.begin(), x.end());
        int l = 1, r = x[n-1] - x[0], m;

        for (i = 0; i < n - 1; i++)
        {
            d[i] = x[i + 1] - x[i];
        }
        
        while (l <= r)
        {
            m = (l + r) / 2;
            ans = m;
            
            i = 0;
            s = 0;
            j = c - 1;
            while (i < n - 1)
            {
                s += d[i];
                if (s >= m)
                {
                    j--;
                    ans = min(s, ans);
                    s = 0;
                }

                if (j <= 0)
                    break;

                i++;
            }

            if (i < (n - 1))
            {
                ans2 = ans;
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }

        cout << ans2 << endl;
    }

    return 0;
}
