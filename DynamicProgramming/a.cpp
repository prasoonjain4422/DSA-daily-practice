#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
const ll MAX_N = INT_MAX;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t, n, i, j, m;

    cin >> t;
    // build();

    while (t--)
    {
        cin >> n;

        if (n == 1 || n == 3)
        {
            cout << "Alice" << endl;
        }
        else if (n == 2)
        {
            cout << "Bob" << endl;
        }
        else
        {
            if (n % 2 == 0)
            {
                cout << "Alice" << endl;
            }
            else if (n % 2 == 1)
            {
                cout << "Bob" << endl;
            }
            else if (n % 2 == 2)
            {
                cout << "Alice" << endl;
            }
            else
            {
                cout << "Bob" << endl;
            }
        }
    }

    return 0;
}
