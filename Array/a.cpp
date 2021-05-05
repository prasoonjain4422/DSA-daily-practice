#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define see(a) cout << a << endl;
const ll M = 1000000007;
using namespace std;

void mul(ll i, vector<ll> &ans)
{
    ll carry = 0;
    ll pro = 1;
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        pro = ((*it) * i) + carry;
        (*it) = pro % 10;
        carry = pro / 10;
    }

    while (carry)
    {
        ans.push_back(carry % 10);
        carry /= 10;
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll i, j, k, n1, n2, n3, t, m, l, s, add, x, f, sum;
    cin >> n1;
    vector<ll> ans;
    ans.push_back(1);

    for (i = 2; i <= n1; i++)
        mul(i, ans);

    reverse(ans.begin(), ans.end());

    for (auto x : ans)
        cout << x << " ";

    return 0;
}
