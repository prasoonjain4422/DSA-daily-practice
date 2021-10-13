#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
// #define ll unsigned long long
using namespace std;
const ll M = 1000000007;

//  (x^y)%M
ll power(ll x, ll y)
{

    if (y == 0)
        return 1;

    ll p = power(x, y / 2) % M;
    p = (p * p) % M;

    if (y % 2 != 0)
        p = (p * x) % M;

    return p;
}

void solve()
{
    ll i, j, k, n, a, b, m, c, l, r, mid, sum;

    cin >> n >> k;

    ll ans = 0ll;
    for (i = 31; i >= 0; i--)
    {
        if (k & (1ll << i))
        {
            ans = (ll)(((ans % M) + (power(n, i) % M)) % M);
        }
    }

    cout << ans << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
