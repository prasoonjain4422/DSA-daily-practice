#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long i, j, a, b, ans = 0, temp = 0;
    int sign = 1;

    cin >> a >> b;
    //  (a/b)

    if ((a < 0) && (b >= 0))
        sign = 0;
    else if ((a >= 0) && (b < 0))
        sign = 0;

    for (i = 31; i >= 0; i--)
    {
        if ((temp + (b << i)) <= a)
        {
            temp += (b << i);
            ans = ans | (1LL << i);
            // cout << i << " rthgf ";
            // cout << (temp + (b << i)) << endl;
        }
    }

    if (!sign)
        cout << "-";
    
    
    cout << ans << endl;

    return 0;
}
