#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j;
    string s;
    int k, x, y, n, g, len, ans = 0, q, m, p;
    unordered_map<string, bool> um;

    cin >> s;
    cin >> q;

    n = s.length();

    while (q--)
    {
        cin >> m >> p;
        ans = 0;
        for (i = 0; (i + m) <= n; i++)
        {
            if (!um[s.substr(i, m)])
            {
                um[s.substr(i, m)] = true;
                if (p == count(s.begin(), s.end(), s.substr(i, m)))
                    ans++;
            }
        }

        um.clear();
        cout << ans << endl;
    }

    return 0;
}
