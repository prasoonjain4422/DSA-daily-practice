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

    ll i, j, k, n1, n2, n3, t, m, l, s, add, x, sum;
    cin >> n1;
    vector<ll> a(n1);

    for (i = 0; i < n1; i++)
        cin >> a[i];

    ll pro = 1, tln = 1, f = 1, ans = 1;
    for (i = 0; i < n1; i++)
    {
        if (a[i] > 0)
        {
            pro *= a[i];
            if (f == 1)
                tln *= a[i];
        }
        else if (a[i] < 0)
        {
            ans = max(ans, pro);
            pro *= a[i];
            if (f == 1)
            {
                tln *= a[i];
                f = 0;
            }
        }
        else
        {
            if (pro < 0)
                ans = max(ans, pro / tln);
            else
                ans = max(ans, pro);

            f = 1;
            pro = 1;
            tln = 1;
        }
    }
    if (pro < 0)
        ans = max(ans, pro / tln);
    else
        ans = max(ans, pro);

    cout << ans;

    return 0;
}
