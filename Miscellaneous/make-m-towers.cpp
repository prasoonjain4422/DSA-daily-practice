#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define see(a) cout << a << endl;
const ll M = 1000000007;
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        ll i, j, k, n, t, m, l, s, add, x, f, sum;
        cin >> t;

        while (t--)
        {
                cin >> n >> m >> x;
                vector<ll> a(n), ans(n);
                map<ll, vector<ll>, greater<ll>> mm;

                for (i = 0; i < n; i++)
                {
                        cin >> a[i];
                        mm[a[i]].pb(i);
                }

                multiset<pair<ll, ll>> hei;
                for (i = 0; i < m; i++)
                        hei.insert({0, i});

                j = 0;
                for (auto xi : mm)
                {
                        for (i = 0; i < xi.second.size(); i++)
                        {
                                ll v = (*(hei.begin())).first;
                                v += xi.first;

                                ans[xi.second[i]] = (*(hei.begin())).second + 1;
                                hei.erase(hei.begin());

                                hei.insert({v, ans[xi.second[i]] - 1});
                                j++;
                        }
                }

                if (((*(hei.rbegin())).first - (*(hei.begin())).first) > x)
                {
                        cout << "NO" << endl;
                }
                else
                {
                        cout << "YES" << endl;
                        for (auto xi : ans)
                                cout << xi << " ";
                        cout << endl;
                }
        }
        return 0;
}
