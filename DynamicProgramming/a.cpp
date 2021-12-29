#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const ll M = 1000000007;

void solve()
{
    ll i, j, k, n, m, mid, sum, f, x, y, ans, finalAns, w;

    cin >> n;

    vector<ll> h(n);

    sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
        sum += h[i];
    }

    j = (sum / n);

    cout << "j = " << j << endl;

    ans = INT_MAX;
    for (i = n - 1; i > 1; i--)
    {

        // j = (min((h[i] / 3 + h[i - 2] / 2), (h[i] / 3 + h[i - 1])));
        if ((h[i - 1] < h[i - 2]) && (h[i] > h[i - 1]))
        {
            j = (h[i] - h[i - 1]) / 3;
        }
        else if (h[i] > h[i - 2])
        {
            j = (2 * (h[i] - h[i - 2])) / 5;
        }
        else
        {
            j = (sum / n);
        
        }
        j = min((sum / n), j);
        
        if (h[i] >= (j + 3))
        {
            k = (h[i] - j);
            k = k - (k % 3);

            h[i] -= k;
            h[i - 1] += (k / 3);
            h[i - 2] += ((2 * k) / 3);
        }

        cout << "   -" << h[i] << endl;
        ans = min(ans, h[i]);
    }

    cout << "   -" << h[1] << endl;
    cout << "   -" << h[0] << endl;
    ans = min(ans, h[1]);
    ans = min(ans, h[0]);

    if (ans == h[0])
    {
    }

    if (ans == h[1])
    {
    }

    cout << ans;
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

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
