// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {

        queue<pair<pair<int, int>, int>> q;
        map<pair<int, int>, bool> vis;
        q.push(make_pair(make_pair(KnightPos[0], KnightPos[1]), 0));

        int x, y, d, ans = INT_MAX;

        while (!q.empty())
        {

            x = (q.front()).first.first;
            y = (q.front()).first.second;
            d = (q.front()).second;
            q.pop();

            if ((x == TargetPos[0]) && (y == TargetPos[1]))
            {
                ans = min(ans, d);
                return ans;
                // continue;
            }

            if (!vis[make_pair(x, y)])
            {
                vis[make_pair(x, y)] = true;

                if ((x - 2) > 0)
                {
                    if ((y - 1) > 0)
                    {
                        q.push(make_pair(make_pair(x - 2, y - 1), d + 1));
                    }

                    if ((y + 1) <= n)
                    {
                        q.push(make_pair(make_pair(x - 2, y + 1), d + 1));
                    }
                }
                if ((x + 2) <= n)
                {
                    if ((y - 1) > 0)
                    {
                        q.push(make_pair(make_pair(x + 2, y - 1), d + 1));
                    }

                    if ((y + 1) <= n)
                    {
                        q.push(make_pair(make_pair(x + 2, y + 1), d + 1));
                    }
                }
                if ((y - 2) > 0)
                {
                    if ((x - 1) > 0)
                    {
                        q.push(make_pair(make_pair(x - 1, y - 2), d + 1));
                    }

                    if ((x + 1) <= n)
                    {
                        q.push(make_pair(make_pair(x + 1, y - 2), d + 1));
                    }
                }
                if ((y + 2) <= n)
                {
                    if ((x - 1) > 0)
                    {
                        q.push(make_pair(make_pair(x - 1, y + 2), d + 1));
                    }

                    if ((x + 1) <= n)
                    {
                        q.push(make_pair(make_pair(x + 1, y + 2), d + 1));
                    }
                }
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends