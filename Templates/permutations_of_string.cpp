#include <bits/stdc++.h>
using namespace std;

// For strings having no repeated characters

void permutation(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string re = str.substr(0, i) + str.substr(i + 1);

        permutation(re, ans + ch);
    }
}

int main()
{
    int t;

    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        permutation(s, "");
    }
    return 0;
}
