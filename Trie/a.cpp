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

    ll t, n, i, j, m, d;

    cin >> n;

    unordered_map<string, int> um;
    vector<int> ans;

    string word;
    for (i = 0; i < n; i++)
    {
        cin >> word;
        sort(word.begin(), word.end());
        um[word]++;
    }

    cin >> m;
    vector<string> sentence(m);
    for (i = 0; i < m; i++)
    {
        cin >> sentence[i];
        cout<<sentence[i]<<" ";
    }

    i = -1;
    int count;
    while (++i < m)
    {
        stringstream s(sentence[i]);
        count = 1;
        while (s >> word)
        {
            cout << word << " ";
            sort(word.begin(), word.end());
            count *= um[word];

            if (count == 0)
                break;
        }

        cout <<count<<"  "<< endl;
        ans.push_back(count);
    }

    for (auto x : ans)
        cout << x << " ";

    return 0;
}
