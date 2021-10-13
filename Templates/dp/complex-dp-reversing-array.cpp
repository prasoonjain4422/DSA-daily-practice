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

        ll i, j, k, n, t, m, l, ans, add;
        cin >> n;
        vector<ll> a(n), b(n), mu(n);
        vector<ll> az(n, 0), az1(n, 0), az2(n, 0);

        for (i = 0; i < n; i++)
                cin >> a[i];

        ans = 0;
        for (i = 0; i < n; i++)
        {
                cin >> b[i];
                ans += a[i] * b[i];
        }

        add = 0;
        for (i = 1; i < n; i++)
        {
                for (j = 0; j < n - i; j++)
                {
                        az[j] = az2[j + 1] + ((a[j] - a[i + j]) * (b[i + j] - b[j]));
                        add = max(add, az[j]);
                }
                az2 = az1;
                az1 = az;
        }

        cout << (ans + add) << endl;

        return 0;
}
