#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, n, t, k, d, ans, k2, d2, ans2;

    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<int> a(n), b(n);

        for (i = 0; i < n; i++)
            cin >> a[i];

        for (i = 0; i < n; i++)
            cin >> b[i];

        k = 0;
        d = 0;
        ans = a[0];
        if (a[0] == b[0])
        {
            d++;
        }

        for (i = 1; i < n; i++)
        {

            if (a[i] == b[i])
            {
                d++;
                ans = ans & a[i];
            }
            else if ((ans & a[i]) > (ans & b[i]))
            {
                ans = ans & a[i];
            }
            else
            {
                k++;
                ans = ans & b[i];
            }
        }
        
        k2 = 0;
        d2 = 0;
        ans2 = b[0];
        if (a[0] == b[0])
        {
            d2++;
        }
        else
        {
            k2++;        
        }

        for (i = 1; i < n; i++)
        {

            if (a[i] == b[i])
            {
                d2++;
                ans2 = ans2 & a[i];
            }
            else if ((ans2 & a[i]) > (ans2 & b[i]))
            {
                ans2 = ans2 & a[i];
            }
            else
            {
                k2++;
                ans2 = ans2 & b[i];
            }
        }
        
        if(ans2 > ans)
        {
            ans = ans2;
            k = k2;
            d = d2;
        }
        

        cout << ans << " " << min(k, n - k - d) << endl;
    }

    return 0;
}
