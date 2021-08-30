#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a(1000);

// Radix sort uses counting sort as a subroutine to sort.
// Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers.
// O(d*(n+b)) = O((n+b)*logbk).

void countSort(ll n, ll e)
{
    ll i;
    vector<ll> count(10), output(n);

    for (i = 0; i < n; i++)
    {
        count[(a[i] / e) % 10]++;
    }

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = 0; i < n; i++)
    {
        output[--count[(a[i] / e) % 10]] = a[i];
    }

    for (i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void radixSort(ll n)
{
    ll m = *max_element(a.begin(), a.end());

    for (ll e = 1; m / e > 0; e *= 10)
    {
        countSort(n, e);
    }
}

int main()
{
    ll n, i;
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> a[i];

    radixSort(n);

    cout << "Sorted" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
