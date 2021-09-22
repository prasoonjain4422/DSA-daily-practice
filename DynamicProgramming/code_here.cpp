#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t, n, i, j, k, m, sum = 0;

    cin >> n;
    vector<ll> as(n);
    vector<vector<ll>> a(n);

    for (i = 0; i < n; i++)
    {
        cin >> as[i];
        a[i].resize(as[i]);
        for (j = 0; j < as[i]; j++)
        {
            cin >> a[i][j];
        }
    }

    string temp;
    cin >> m;
    unordered_map<string, bool> um;
    vector<vector<int>> bb(m);

    for (i = 0; i < m; i++)
    {
        bb[i].resize(n);
        temp = "";
        for (j = 0; j < n; j++)
        {
            cin >> bb[i][j];
            temp += to_string(bb[i][j]);
        }

        um[temp] = true;
    }

    vector<int> mb(n);
    for (i = 0; i < n; i++)
        mb[i] = as[i];

    // for (i = 0; i < n; i++)
    //     cout << mb[i] << " ";
    // cout << endl;

    temp = "";
    for (j = 0; j < n; j++)
    {
        temp += to_string(mb[j]);
    }

    string t2 = "", t3 = "";
    if (um[temp])
    {

        ll d = INT_MAX;
        for (i = 0; i < n; i++)
        {
            int it = 0;
            while ((mb[i] - it) > 1)
            {
                // cout << (a[i][mb[i] - 1] - a[i][mb[i] - 2]) << endl;
                t2 = temp;
                t2[i] = (a[i][mb[i] - 2] + 48);

                if ((d > (a[i][mb[i] - 1] - a[i][mb[i] - 2])) && (!um[t2]))
                {
                    d = a[i][mb[i] - 1] - a[i][mb[i] - 2];
                    t3 = t2;
                    break;
                }

                it++;
            }
        }
    }

    // temp = "";
    // for (j = 0; j < n; j++)
    // {
    //     temp += to_string(mb[j]);
    // }

    if (t3 != "")
        temp = t3;

    for (i = 0; i < n; i++)
        cout << t3[i] << " ";

    return 0;
}
