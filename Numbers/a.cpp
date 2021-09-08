#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, n, k, d = 0;

    cin >> n >> k;
    // cout << n << k << endl;

    string s = "";

    while (n > 0)
    {
        s = to_string((n % 10)) + s;
        n = n / 10;
        d++;
    }

    for (i = 0; i < d; i++)
    {
        if (s[i] != s[d - 1 - i])
        {
            break;
        }
    }

    if (i >= d)
    {
        k++;
        // cout << "inc" << endl;
    }

    int c = 0, p = 0;
    while (k > c)
    {

        // cout << "inc" << endl;
        // c = 0;
        p = 0;
        i = (d - 1) / 2;
        // cout << d;
        if (d % 2 == 0)
            j = i + 1;
        else
            j = i;

        while (i >= 0)
        {

            if (s[i] < s[j])
                c += 10 - ((int)(s[i]) + 1 - 48) + 10 * p;
            else
                c += 10 - ((int)(s[j]) - 48) + 10 * p;

            // cout << c << endl;
            if (c >= k)
            {
                s[i] = ((char)(9 - c + k + 48));
                s[j] = s[i];
                break;
            }
            else
            {
                i--;
                j++;
                p++;
            }
        }

        if (c >= k)
        {
            break;
        }

        // cout << s << endl;
        for (int x = 0; x < d; x++)
        {
            s[x] = 48;
        }
        s = "1" + s;
        d++;
        // cout << s << endl;
    }

    while (i >= 0)
    {
        if (s[i] < s[j])
            s[i] = (char)((int)s[i] + 1);
        else
            s[i] = s[j];

        s[j] = s[i];
        i--;
        j++;
    }

    if (s[0] == '0')
    {
        s[0] = '1';
        s[d - 1] = '1';
    }

    cout << s;

    return 0;
}
