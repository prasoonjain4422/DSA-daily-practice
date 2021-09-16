#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> um, ld, rd;
void arrange(int c, int n, vector<string> &ans, string s)
{

    if (c == n + 1)
    {
        ans.push_back(s);
        return;
    }

    int i;
    for (i = 1; i <= n; i++)
    {
        if ((!um[i]) && (!ld[i - c]) && (!rd[i + c]))
        {
            um[i] = true;
            ld[i - c] = true;
            rd[i + c] = true;
            arrange(c + 1, n, ans, s + " " + to_string(i));
            um[i] = false;
            ld[i - c] = false;
            rd[i + c] = false;
        }
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, n, t, sum = 0;

    cin >> n;
    vector<string> ans;
    um.clear();
    ld.clear();
    rd.clear();

    arrange(1, n, ans, "");

    for (auto x : ans)
    {
        cout << x << endl;
    }

    return 0;
}
