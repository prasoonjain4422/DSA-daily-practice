#include <bits/stdc++.h>
#define ll long long
#define endl "\n";
using namespace std;

vector<int> Pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                  31, 37, 41, 43, 47, 53, 59, 61, 67,
                  71, 73, 79, 83, 89, 97};

void primeFactors(ll n)
{
    while (n % 2 == 0)
    {
        cout << "2 ";
        n = n / 2;
    }

    for (ll i = 3; i < n; i += 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }

    if (n > 2)
        cout << n;
}

int main()
{
    ll t, n, k, i, j;
    cin >> t;
    while (t--)
    {
        cin >> n;
        primeFactors(n);
        cout << endl;
    }
    return 0;
}
