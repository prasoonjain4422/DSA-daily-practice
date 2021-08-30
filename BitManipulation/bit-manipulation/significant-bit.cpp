#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll getMSB(ll n)
{
    return log2(n);
}

ll getLSB(ll n)
{
    return log2(n ^ (n - 1));
}

int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << getMSB(n) << endl;
        cout << getLSB(n) << endl;
    }
    return 0;
}