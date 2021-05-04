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

    cin >> n;
    vector<ll> a(n);

    for (i = 0; i < n; i++)
        cin >> a[i];

    i = 0, j = 1;

    while ((i < n) && (j < n))
    {
        while ((i < n) && (a[i] < 0))
            i += 2;

        while ((j < n) && (a[j] > 0))
            j += 2;

        if ((i < n) && (j < n))
        {
            swap(a[i], a[j]);
        }
    }

    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
