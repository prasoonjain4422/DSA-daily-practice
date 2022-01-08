#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const ll M = 1000000007;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return ((a * b) / gcd(a, b));
}

void solve()
{
    ll i, j, k, n, m, mid, f, y, ans, finalAns, w, l, r;
    cin >> n;

    vector<ll> a(n);

    ll sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    m = n / 2;
    sort(a.begin(), a.end());
    if (n % 2 == 0)
    {
        m--;
    }

    double me = (sum / n);
    double md = a[m];

    if (md == me)
    {
        cout << 0 << endl;
        return;
    }

    if (me > md)
    {
        ll d;
        if (sum % n != 0)
            d = n - (sum % n);
        else
            d = 0;

        ans = d;
        sum += d;

        double dd = (((double)((double)sum / (double)n) - (double)a[m])) / (double)(n - 1);

        j = dd;

        // cout << ans << " " << dd << " ";
        if ((double)j != dd)
        {
            j++;
        }

        d = n * j;
        // d = n * (((sum / n) - a[m]) / (n - 1));

        cout << (ans + d) << endl;
    }
    else
    {
        ans = (n * a[m]) - sum;
        cout << ans << endl;
    }
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
