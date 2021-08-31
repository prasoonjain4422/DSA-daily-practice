#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, n, k;

    cin >> k;
    n = 1;
    i = 10;


    if (k % 2 == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    if (k % 5 == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    while (true)
    {
        if (n % k == 0)
        {
            cout << n << endl;
            break;
        }
        else
        {
            n += i;
            i *= 10;
        }
    }

    return 0;
}
