#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define see(a) cout << a << endl;
const ll M = 1000000007;
using namespace std;
ll ans=0;

void merge(ll l, ll m, ll r, vector<ll> &a)
{
    
}

void mergeS(ll l, ll r, vector<ll> &a)
{
    if(l>=r)
        return;
    
    ll m = (l+r)/2;
    
    mergeS(l, m, a);
    mergeS(m+1, r, a);
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

    mergeS(0, n-1, a);

    return 0;
}
