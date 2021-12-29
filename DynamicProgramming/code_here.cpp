#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const ll M = 1000000007;

class Solution
{
public:
    bool prime[1000000 + 2];

    void SieveOfEratosthenes()
    {
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= 1000000; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= 1000000; i += p)
                    prime[i] = false;
            }
        }
    }

    void solve()
    {
        ll i, j, k, n, m, sum, f, v, x, y, r, l, p, q, e, pf;
        ll ans = 0;

        cin >> n;

        cout << pow(n, ((double)1 / (double)5));

        cout << endl;
    }
};

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

    Solution obj;
    // obj.SieveOfEratosthenes();
    while (t--)
    {
        obj.solve();
    }

    return 0;
}
