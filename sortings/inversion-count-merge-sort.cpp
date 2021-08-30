#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a(1000);
ll inv;

// Time complexity of this by brute force is  θ(n2)
// But, Time complexity of this by this mergeSort is  θ(nLogn)

void merge(ll l, ll m, ll r)
{
    ll i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    vector<ll> le(n1), ri(n2);

    for (i = 0; i < n1; i++)
        le[i] = a[l + i];

    for (i = 0; i < n2; i++)
        ri[i] = a[m + 1 + i];

    i = 0;
    j = 0;
    k = l;
    while ((i < n1) && (j < n2))
    {
        if (le[i] <= ri[j])
        {
            a[k] = le[i];
            i++;
        }
        else
        {
            inv += n1 - i;
            a[k] = ri[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = le[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = ri[j];
        j++;
        k++;
    }
}

void mergeSort(ll l, ll r)
{

    if (l >= r)
        return;

    ll m = (l + r) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge(l, m, r);
}

int main()
{
    ll n, i;
    cin >> n;
    inv = 0;

    for (i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(0, n - 1);

    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "inv = " << inv;

    return 0;
}
