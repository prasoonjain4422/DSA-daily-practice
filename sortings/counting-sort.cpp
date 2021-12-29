#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a(1000);
vector<ll> b(1000);

//----> Time complexity is O(n+k)
//----> Auxiliary space is O(n+k)
//----> if k(range of input data) = n^2, then time complexity
//      will be O(n^2)


void countingSort(ll n)
{
    ll i, min = *min_element(a.begin(), a.end());
    ll s = *max_element(a.begin(), a.end()) - min + 1;
    vector<ll> count(s);

    for (i = 0; i < n; i++)
    {
        count[a[i] - min]++;
    }

    // making prefix sum of counting array
    for (i = 1; i <= s; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = 0; i < n; i++)
    {
        b[--count[a[i] - min]] = a[i];
    }
}

int main()
{
    ll n, i;
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> a[i];

    countingSort(n);

    cout << "Sorted" << endl;
    for (i = 0; i < n; i++)
        cout << b[i] << " ";

    return 0;
}
