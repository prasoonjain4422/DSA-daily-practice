#include <bits/stdc++.h>
#define ll long long int
#define endl "\n";
using namespace std;

bool powerof2(ll n)
{
    if (((n) & (n - 1)) == 0)
        return true;
    else
        return false;
}

int main()
{
    ll n;
    cin >> n;

    if (powerof2(n))
        cout << "Power of 2";
    else
        cout << "Not Power of 2";

    return 0;
}
