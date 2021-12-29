#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int i, n = s.size();
    vector<int> m(10, 0);

    for (i = 0; i < n; i++)
    {
        m[((int)s[i] - 48)]++;
    }

    s = "";
    for (i = 9; i >= 0; i--)
    {
        if (m[i] > 0)
        {
            while (m[i]--)
            {
                s = s + to_string(i);
            }
        }
    }

    cout << s << endl;
    return 0;
}
