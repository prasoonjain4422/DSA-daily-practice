#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    int p = 1;
    for (int i = 2; i <= n; i++)
        p *= i;

    return p;
}

void fun(vector<int> &a, int n, int k)
{
    cout << endl;
    int it, i, s = 0, f;
    unordered_set<int> us;

    i = 1;
    f = fact(n - i);

    for (it = 1; it <= n; it++)
    {
        if (us.find(it) != us.end())
            continue;

        if ((s + f) <= k)
        {
            s += f;
            if (s == k)
                break;
        }
        else
        {
            us.insert(it);
            it = 0;
            f = f / (n - i);
            i++;
        }
    }

    vector<int> v(us.begin(), us.end());

    for (auto x = v.rbegin(); x != v.rend(); x++)
        cout << (a[*x - 1]);

    if (f == 1)
    {
        for (it = 1; it <= n; it++)
        {
            if (us.find(it) == us.end())
            {
                cout << a[it - 1];
            }
        }
    }
    else
    {
        cout << it;
        us.insert(it);
        for (it = n; it >= 1; it--)
        {
            if (us.find(it) == us.end())
            {
                cout << a[it - 1];
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, i, k;
        cin >> n >> k;
        vector<int> a(n);

        for (i = 0; i < n; i++)
            cin >> a[i];

        fun(a, n, k);
    }
    return 0;
}
