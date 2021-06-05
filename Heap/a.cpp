#include <bits/stdc++.h>
using namespace std;

void heapify(int a[], int i, int n)
{

    int l = i;
    if (((2 * i + 1) < n) && (a[2 * i + 1] > a[l]))
    {
        l = 2 * i + 1;
    }

    if (((2 * i + 2) < n) && (a[2 * i + 2] > a[l]))
    {
        l = 2 * i + 2;
    }

    if (i != l)
    {
        swap(a[l], a[i]);
        heapify(a, l, n);
    }
}

void buildHeap(int a[], int n)
{
    int i;
    for (i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(a, i, n);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, i;

    cin >> n;
    int a[n];

    for (i = 0; i < n; i++)
        cin >> a[i];

    buildHeap(a, n);

    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
