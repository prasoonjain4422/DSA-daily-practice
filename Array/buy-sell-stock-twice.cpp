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

    ll i, j, k, n, n1, n2, n3, t, m, l, s, add, mx1 = 0, mx2 = 0, sum;

    cin >> n;
    vector<ll> a(n);

    for (i = 0; i < n; i++)
        cin >> a[i];

    l = a[0];
    ll dif = 0;
    multiset<ll, greater<ll>> ms;
    for (i = 1; i < n; i++)
    {
        if (l >= a[i])
        {
            l = a[i];
            ms.insert(dif);
        }
        else
        {
            if (dif < (a[i] - l))
                dif = (a[i] - l);
        }
    }
    ms.insert(dif);

    auto it = ms.begin();
    cout << *it << " ";
    it++;
    cout << *it << " ";

    return 0;
}
