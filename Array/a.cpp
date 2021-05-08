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

    ll n, n1, n2, n3, t, m, l, mx1 = 0, mx2 = 0, sum, i, j, k;

    cin >> k >> n;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    int intervals = 1;
    int s[n * n];
    int b[n * n];
    int inter;
    int add, sub, ans = arr[n - 1] - arr[0];
    b[0] = arr[n - 1] - k, s[0] = arr[0] + k;
    if (s[0] > b[0])
        swap(s[0], b[0]);

    for (j = 0; j < intervals; j++)
    {
        cout << j << "j   " << s[j] << " " << b[j] << endl;
    }
    cout << endl;
    cout << endl;

    for (i = 1; i < n - 1; i++)
    {
        add = arr[i] + k;
        sub = arr[i] - k;

        inter = intervals;
        for (j = 0; j < intervals; j++)
        {
            if ((sub >= s[j]) || (add <= b[j]))
                continue;

            cout << i << "i j" << j << endl;
            if (sub >= 0)
            {
                s[inter] = s[j];
                s[j] = sub;
                b[inter] = add;
                inter++;
                // cout<<"new  "<<s[inter]<<" "<<
            }
            else
            {
                b[j] = add;
            }
            cout << j << "j   " << s[j] << " modified " << b[j] << endl;
        }
        intervals = inter;
    }

    for (j = 0; j < intervals; j++)
    {
        ans = min(ans, (b[j] - s[j]));
        cout << j << "j   " << s[j] << " " << b[j] << endl;
    }

    cout << ans;

    return 0;
}
