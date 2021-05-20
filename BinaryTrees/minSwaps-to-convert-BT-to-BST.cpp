// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> nums);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t, n;
    scanf("%d ", &t);
    while (t--)
    {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        cout << minSwaps(v) << endl;
    }
    return 1;
} // } Driver Code Ends

int minSwaps(vector<int> nums)
{
    int n = nums.size();
    pair<int, int> arr[n];
    int ans = 0;
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++)
    {
        arr[i].first = nums[i];
        arr[i].second = i;
    }

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if ((vis[i]) || (arr[i].second == i))
            continue;

        int cycle = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            cycle++;
            j = arr[j].second;
        }
        ans += max(0, cycle - 1);
    }

    return ans;
}
