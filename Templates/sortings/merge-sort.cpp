#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a(1000);

// Time complexity of Merge Sort is  θ(nLogn)
// in all 3 cases (worst, average and best)
// as merge sort always divides the array
// into two halves and takes linear time to merge two halves.


void merge(ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 = r - m;

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
    {
        return;
    }

    ll m = (l + r) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge(l, m, r);
}

int main()
{
    ll n, i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(0, n - 1);

    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}
