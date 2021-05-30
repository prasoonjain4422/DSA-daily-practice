#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i <= (n / 2); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}


int fun(string s, int ind)
{
    int i, j, ans = 0, fans = 0, n = s.size();

    if (ind >= n)
        return 1;

    // cout << "fun  " << ind << endl;

    for (i = 1; (i + ind) <= s.size(); i++)
    {
        // cout << "lenght " << i << endl;

        ans = 0;
        j = stoi(s.substr(ind, min(i, n - ind)));

        if (isPrime(j))
        {
            // cout << j << " selected ";
            ans += fun(s, ind + i);
        }

        if (ans > 0)
            fans += ans;
    }

    return fans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        vector<int> v;

        cout << fun(s, 0);
    }
    return 0;
}
