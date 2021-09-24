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

    int n, i, j, m, x;
    string s;
    cin >> s;
    n = s.length();

    vector<pair<int, int>> p;                   // pairs
    vector<bool> vis(26, false);

    for (i = 0; i < n; i++)
    {
        if (!vis[s[i] - 'a'])
        {
            vis[s[i] - 'a'] = true;
            for (j = n - 1; j >= 0; j--)
            {
                if (s[j] == s[i])
                {
                    break;
                }
            }
            cout << i << " " << j << endl;
            p.push_back({i, j});
        }
    }

    for (i = 0; i < p.size(); i)
    {
        // cout << i << endl;
        j = i + 1;
        for (j; j < p.size(); j++)
        {
            if ((p[i].first < p[j].first) && (p[j].first < p[i].second))
            {
                p[i].second = max(p[i].second, p[j].second);
                p[j].first = -1;
                p[j].second = -1;
            }
            else
            {
                break;
            }
        }
        
        i = j;
    }

    for (i = 0; i < p.size(); i++)
    {
        if (p[i].first != -1)
        {
            for (j = p[i].first; j <= p[i].second; j++)
            {
                cout << s[j];
            }
            cout << " ";
        }
    }

    return 0;
}
