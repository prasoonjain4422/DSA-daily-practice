#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t, n, i, j, m, k, key;

    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<pair<int, int>> ans;
        multiset<pair<int, int>> a;
        for (i = 0; i < n; i++)
        {
            cin >> j;
            if (j > 0)
                a.insert({j, i});
        }

        while (a.size() > 1)
        {

            auto x = *a.begin();
            auto y = *prev(a.end());
            a.erase(a.begin());
            a.erase(prev(a.end()));

            x.first--;
            y.first--;

            if (x.first > 0)
                a.insert(x);
            if (y.first > 0)
                a.insert(y);

            if (x.second > y.second)
                swap(x, y);

            ans.push_back({x.second + 1, y.second + 1});
        }

        cout << ans.size() << endl;

        for (auto x : ans)
        {
            cout << x.first << " " << x.second << endl;
        }
    }

    return 0;
}
