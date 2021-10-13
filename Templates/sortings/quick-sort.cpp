#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a(1000);
//----> Not-stable
//----> in-place (it qualifies as an in-place sorting
// algorithm as it uses extra space only for storing
// recursive function calls but not for manipulating the input.)

// Time complexity is O(nlogn)


ll partition(ll low, ll high)
{
    //we are taking the last element as pivot
    // pivot = a[high]
    ll i, j;
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (a[j] < a[high])
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}
// The worst case occurs when the partition process
// always picks greatest or smallest element as pivot.


void quickSort(ll low, ll high)
{
    if (low < high)
    {
        ll pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main()
{
    ll n, i;
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> a[i];

    quickSort(0, n - 1);

    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
