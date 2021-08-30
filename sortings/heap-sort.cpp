#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a(1000);

//Time complexity of heapify is O(Logn).
//Time complexity of createAndBuildHeap()is O(n)
//and overall time complexity of Heap Sort is O(nLogn)

void heapify(ll m, ll i)
{
    ll largest = i;
    ll l = 2 * i + 1;
    ll r = 2 * i + 2;

    if (l < m && a[l] > a[largest])
        largest = l;

    if (r < m && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(m, largest);
    }
}

void heapSort(ll n)
{
    ll i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(i, 0);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];

    heapSort(n);

    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}
