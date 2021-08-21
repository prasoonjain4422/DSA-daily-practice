#include <bits/stdc++.h>
const int M = 1000000007;

using namespace std;
int n, k;

int paint(int i, int d, vector<int> adj[], int dp[][2])
{

    int ans = 0, ans2 = 1;
    if (d <= 0)
    {
        if (dp[i][0] == -1)
        {

            ans = 1;
            for (auto x : adj[i])
            {
                ans = (ans * paint(x, k - 1, adj, dp)) % M;
            }

            dp[i][0] = ans;
        }
        else
        {
            ans = dp[i][0];
        }
    }

    if (dp[i][1] == -1)
    {
        for (auto x : adj[i])
        {
            ans2 = (ans2 * paint(x, d - 1, adj, dp)) % M;
        }

        dp[i][1] = ans2;
    }
    else
    {
        ans2 = dp[i][1];
    }

    return (ans + ans2) % M;
}

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second < b.second);
}

int minpoints(int input1, vector<pair<int, int>> &input2)
{

    int i, ans = 1, j;
    sort(input2.begin(), input2.end());

    j = input2[0].second;

    for (i = 1; i < n; i++)
    {
        if ((j >= input2[i].first) && (j <= input2[i].second))
        {
        }
        else
        {
            ans++;
            j = max(j, input2[i].second);
        }
    }

    return ans;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, p, q;

    cin >> n;
    vector<pair<int, int>> a(n);

    for (i = 0; i < n; i++)
    {
        cin >> p >> q;
        a[i] = {p, q};
    }

    cout << minpoints(n, a) << endl;

    return 0;
}