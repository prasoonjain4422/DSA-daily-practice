#include <bits/stdc++.h>
#define endl "\n"
// #define ll long long int
#define ll int
using namespace std;
const ll MAX_N = INT_MAX;

void lis(int n, vector<int> &arr, vector<bool> &x)
{
    int lis[n], pre[n];

    lis[0] = 1;
    pre[0] = 0;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        pre[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] >= arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
                pre[i] = j;
            }
        }
    }

    int i = max_element(lis, lis + n) - lis;
    x[i] = true;

    do
    {
        i = pre[i];
        x[i] = true;
    } while (i != pre[i]);
}

void lds(int n, vector<int> &arr, vector<bool> &x)
{
    int lis[n], pre[n];

    lis[0] = 1;
    pre[0] = 0;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        pre[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
                pre[i] = j;
            }
        }
    }

    int i = max_element(lis, lis + n) - lis;
    // cout << "her " << i << endl;
    x[i] = true;

    do
    {
        i = pre[i];
        x[i] = true;
        // cout << " " << i ;
    } while (i != pre[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t, n, i, j, m;

    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<ll> a(n);
        vector<bool> i(n, false), d(n, false);

        for (int j = 0; j < n; j++)
            cin >> a[j];

        lis(n, a, i);
        lds(n, a, d);

        int ans = 0;

        for (int j = 0; j < n; j++)
        {
            if (i[j] && d[j])
            {
                // cout << "         " << a[j] << endl;
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
