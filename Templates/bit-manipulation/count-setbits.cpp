#include <bits/stdc++.h>
#define ll long long int
#define endl "\n";
using namespace std;

ll countsetbits(ll n)
{
    ll ans = 0;
    while (n != 0)
    {
        ans++;
        n = (n) & (n - 1);
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    cout << countsetbits(n);

    return 0;
}
