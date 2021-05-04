#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define see(a) cout << a << endl;
const ll M = 1000000007;
using namespace std;
ll ans = 0;

void merge(ll l, ll m, ll r, vector<ll> &a)
{
    ll l1 = m - l + 1, l2 = r - m, i, j, k;

    vector<ll> le(l1), re(l2);

    for (i = 0; i < l1; i++)
        le[i] = a[i + l];

    for (i = 0; i < l2; i++)
        re[i] = a[i + m + 1];

    i = 0, j = 0, k = l;
    while ((i < l1) && (j < l2))
    {
        if (le[i] > re[j])
        {
            a[k++] = re[j++];
            ans += l1 - i;
            // cout << l1 - i << " k " << l1 << " " << i << endl;
        }
        else
        {
            a[k++] = le[i++];
        }
    }

    while (j < l2)
    {
        a[k++] = re[j++];
    }

    while (i < l1)
    {
        a[k++] = le[i++];
    }
}

void mergeS(ll l, ll r, vector<ll> &a)
{
    if (l >= r)
        return;

    ll m = (l + r) / 2;

    mergeS(l, m, a);
    mergeS(m + 1, r, a);
    merge(l, m, r, a);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, i, j, k;
    cin >> n;

    vector<ll> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];

    ans = 0;
    mergeS(0, n - 1, a);

    cout << ans << " ans" << endl;

    return 0;
}
