#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int i, n;
    cin >> n;
    vector<int> a(n);

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = 0;
    int r = n - 1;
    int m;

    if (a[0] > a[1])
    {
        cout << a[0];
        return 0;
    }
    //sorted   1 2 3 4 5 6
    //rotated  4 5 6 1 2 3

    while (l <= r)
    {
        m = (l + r) / 2;
        if ((a[m] > a[m + 1]) && (m == 0))
        {
            cout << "-1";
            return 0;
        }
        else if ((a[m] > a[m - 1]) && (m == n-1))
        {
            cout << "-1";
            return 0;
        }
        else if ((a[m] > a[m + 1]) && (a[m] > a[m - 1]))
        {
            cout << a[m];
            return 0;
        }
        else if (a[m] > a[0])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << "-1";
    return 0;
}

// This code is contributed by Vivek Garg in a
// comment on below set 1.
// www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/