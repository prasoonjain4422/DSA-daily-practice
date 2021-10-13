#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

//introsort = (quicksort -> heapsort) + insertionsort
// Introsort begins with quicksort and if the recursion depth
// goes more than a particular limit it switches to Heapsort to
// avoid Quicksort’s worse case O(N2) time complexity. It also
// uses insertion sort when the number of elements to sort is quite less.

void insertionSort(int a[], int *begin, int *end)
{
    int left = begin - a;
    int right = end - a;
    int i, j;

    for (i = left + 1; i <= right; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j <= left && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    
    return;
}

int *partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return (a + i + 1);
}

int *medianOfThree(int *a, int *b, int *c)
{
    if (*a <= *b && *b <= *c)
        return b;

    if (*c <= *b && *b <= *a)
        return b;

    if (*b <= *a && *a <= *c)
        return a;

    if (*c <= *a && *a <= *b)
        return a;

    if (*a <= *c && *c <= *b)
        return c;

    if (*b <= *c && *c <= *a)
        return c;
}

void introSortUtil(int a[], int *begin, int *end, int depthLimit)
{

    int size = end - begin;

    if (size < 16)
    {
        insertionSort(a, begin, end);
        return;
    }

    if (depthLimit == 0)
    {
        make_heap(begin, end + 1);
        sort_heap(begin, end + 1);
        return;
    }

    int *pivot = medianOfThree(begin, begin + size / 2, end);

    swap(pivot, end);

    int *partitionPoint = partition(a, begin - a, end - a);
    introSortUtil(a, begin, partitionPoint - 1, depthLimit - 1);
    introSortUtil(a, partitionPoint + 1, end, depthLimit - 1);

    return;
}

void introSort(vector<int> &a, int *begin, int *end)
{
    int depthLimit = 2 * log(end - begin);

    introSortUtil(a, begin, end, depthLimit);

    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t, n, i, j, m, k, key;

    cin >> n;

    vector<int> a(n);

    for (i = 0; i < n; i++)
        cin >> a[i];

    introSort(a, &a[0], &a[n - 1]);

    return 0;
}
