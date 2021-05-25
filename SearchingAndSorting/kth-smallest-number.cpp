#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, q, i, j;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        vector<pair<int, int>> v(n);

        for (i = 0; i < n; i++)
        {
            cin >> v[i].first;
            cin >> v[i].second;
        }

        while (q--)
        {
            cin >> j;
            for (i = 0; i < n; i++)
            {
                if (v[i].first + j <= v[i].second)
                {
                    cout << (v[i].first + j) << " ";
                }
                else
                {
                    cout << "-1 ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}