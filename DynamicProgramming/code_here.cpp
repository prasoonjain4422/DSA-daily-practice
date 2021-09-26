#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

bool prime(ll n)
{
    for (ll i = 3; i < n; i += 2)
    {
        while (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t, n, i, j, m;

    cin >> t;
    
    while (t--)
    {
        cin >> n;
        
        
    }
    
    return 0;
}

