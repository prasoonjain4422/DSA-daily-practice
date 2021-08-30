#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a(1000);

// we create n buckets
// and then sort each bucket
// independently by insertion sort.
// O(n + k) for best case and average case
// and O(n^2) for the worst case.


void bucketSort(ll n)
{
    ll i, bi, index = 0;
    vector<vector<float>> b(n);

    for (i = 0; i < n; i++)
    {
        bi = n * a[i];
        b[bi].push_back(a[i]);
    }

    for (i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    for (i = 0; i < n; i++)
    {
        for (bi = 0; bi < b[i].size(); bi++)
            a[index++] = b[i][bi];
    }
}

int main()
{
    ll n, i;
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> a[i];

    bucketSort(n);

    cout << "Sorted" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
