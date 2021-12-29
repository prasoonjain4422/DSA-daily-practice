#include <bits/stdc++.h>
using namespace std;

// brute force will be find the sorted array

class Solution
{
public:
    int minSwaps(int a[], int n)
    {
        // Efficient
        // O(nlogn)

        int ans = 0;

        vector<pair<int, int>> mm;

        for (int i = 0; i < n; i++)
        {
            mm.push_back({a[i], i});
        }

        sort(mm.begin(), mm.end());

        // for (int i = 0; i < n; i++)
        // {
        //     cout << mm[i].first << " " << mm[i].second << endl;
        // }
        // cout << endl;


        bool vis[n];
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vis[i] = true;
                if (i != mm[i].second)
                {

                    int circle = 1;

                    int j = mm[i].second;
                    while ((!vis[j]) && (j != mm[j].second))
                    {
                        vis[j] = true;
                        circle++;

                        j = mm[j].second;
                    }

                    if (circle > 1)
                        ans += circle - 1;
                }
            }
        }

        return ans;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t, k;
    cin >> t;

    Solution obj;
    while (t--)
    {
        int n, i;
        cin >> n;

        int a[n];

        for (auto &x : a)
            cin >> x;

        cout << obj.minSwaps(a, n);
    }

    return 0;
}
