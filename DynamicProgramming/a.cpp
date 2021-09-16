#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, n, t, k, d, ans, k2, d2, ans2, sum = 0;

    cin >> t;

    while (t--)
    {

        cin >> n >> k;
        j = 0;
        d = 0;

        vector<int> a(n), b(n, 0);
        unordered_map<int, int> deg;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        
        
        if (a[0] <= 0)
        {
            if(a[n-1] > 0)
                b[0] = 1;
            else if(a[1] > 0)
                b[0] = 1;
            else
                b[0] = INT_MIN;
        }
        else
        {
            j++;
        }
        
        if (a[n-1] <= 0)
        {
            if(a[n-2] > 0)
                b[n-1] = 1;
            else if(a[0] > 0)
                b[n-1] = 1;
            else
                b[n-1] = INT_MIN;
        }
        else
        {
            j++;
        }
        
        for (i = 1; i < n-1; i++)
        {
            if (a[i] <= 0)
            {
                b[i] = b[i - 1] + 1;
            }
            else
            {
                j++;
            }
        }

        if (j == n)
        {
            cout << sum + (2 * n * k) << endl;
            continue;
        }

        for (i = n - 2; i > 0; i++)
        {
            if (a[i] <= 0)
            {
                b[i] = min(b[i + 1] + 1, b[i]);

                deg[b[i]]++;
            }
        }

        ans = sum;
        d = 1;
        while (k--)
        {
            ans += (2 * j);
            j += deg[d++];

            if (j == n)
                break;
        }

        if (k > 0)
        {
            ans += 2*n*k;
        }

        cout << ans << endl;
    }

    return 0;
}
