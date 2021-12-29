#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const ll M = 1000000007;

void solve()
{
    ll i, j, k, n, m, mid, sum, f, x, y, r, l, ans, finalAns, w, h, q;

    cin >> q;
    n = 1;
    map<ll, ll> mmans;
    map<ll, vector<ll>> mm;

    while (q--)
    {

        cin >> i;

        if (i == 1)
        {
            cin >> x;
            mm[x].push_back(n);
            n++;
        }
        else
        {
            cin >> x >> y;

            if (mm[x].size() > 0)
            {
                vector<ll> temp = mm[x];
                mm.erase(x);

                if (mm[y].size() == 0)
                {
                    mm[y] = temp;
                }
                else
                {
                    mm[y].insert(mm[y].end(), temp.begin(), temp.end());
                }
            }
        }

        // for (auto u : mm)
        // {
        //     cout << u.first << " -- ";
        //     for (auto v : u.second)
        //     {
        //         cout << v << " ";
        //     }
        // }
        // cout << endl;
    }

    for (auto u : mm)
    {
        for (auto v : u.second)
        {
            mmans[v] = u.first;
        }
    }

    // cout << endl;
    // cout << endl;
    for (auto v : mmans)
    {
        cout << v.second << " ";
    }

    cout << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll t;
    // cin >> t;

    // while (t--)
    // {
    solve();
    // }

    return 0;
}
