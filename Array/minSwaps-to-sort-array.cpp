// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        pair<int, int> arr[n];
        int ans = 0;
        vector<bool> vis(n);

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
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends