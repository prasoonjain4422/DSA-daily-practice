#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define see(a) cout << a << endl;
#define showa(a)                               \
    for (ll z = (0); z < ((int)a.size()); z++) \
    {                                          \
        cout << (a[z]) << " ";                 \
    }
const ll M = 1000000007;
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, n1, n2, n3, t, m, l, s, add, mx1 = 0, mx2 = 0, sum;

    int i = 0, j = 0, k = 0, a, b;

    cin >> n;
    vector<int> ar(n);
    for (i = 0; i < n; i++)
        cin >> ar[i];

    cin >> a >> b;
    
    a--;
    i = 0;
    while ((i < n) && (ar[i] <= a))
        i++;

    cout << i << endl;
    for (k = i + 1; k < n; k++)
    {
        if (ar[k] <= a)
        {
            if (i < n)
            {
                swap(ar[k], ar[i]);
                i++;
                showa(ar);
                cout << endl;
            }
            while ((i < n) && (ar[i] <= a))
                i++;
        }
    }

    i = 0;
    while ((i < n) && (ar[i] <= b))
        i++;

    cout << endl;
    cout << i << endl;
    cout << endl;

    for (k = i + 1; k < n; k++)
    {
        if (ar[k] <= b)
        {
            if (i < n)
            {
                swap(ar[k], ar[i]);
                i++;
                showa(ar);
                cout << endl;
            }
            while ((i < n) && (ar[i] <= b))
                i++;
        }
    }

    showa(ar);
    cout << endl;
    for (i = 0; i < n; i++)
        cout << ar[i] << " ";

    return 0;
}
