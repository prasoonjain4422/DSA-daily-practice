#include <bits/stdc++.h>
using namespace std;

void rearrange(int a[], int n)
{
    int i, j = n - 1, s;
    while ((j > 0) && (a[j] > 0))
        j--;

    for (i = 0; i < n; i++)
    {
        if (i >= j)
            break;

        if (a[i] > 0)
        {
            s = a[i];
            a[i] = a[j];
            a[j] = s;
            j--;
            while ((j > 0) && (a[j] > 0))
                j--;
        }
    }
}

int main()
{
    int i, n;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];

    rearrange(a, n);

    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}