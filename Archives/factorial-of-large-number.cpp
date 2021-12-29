#include <bits/stdc++.h>
using namespace std;

// brute force will be finding all permutations
// and store them in sorted order and give output
// the next permutation of input

class Solution
{
public:
    void multiply(vector<int> &ans, int m)
    {

        int carry = 0, product = 1;
        for (auto it = ans.begin(); it != ans.end(); it++)
        {
            product = ((*it) * m) + carry;
            *it = product % 10;
            carry = product / 10;
        }

        while (carry > 0)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }

    vector<int> factorial(int n)
    {

        vector<int> ans;
        ans.push_back(1);

        for (int i = 2; i <= n; i++)
        {
            // cout << i << endl;
            multiply(ans, i);
        }

        reverse(ans.begin(), ans.end());
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
        // string s;
        cin >> n;
        cout << n;

        vector<int> ans = obj.factorial(n);

        for (auto x : ans)
            cout << x;
    }

    return 0;
}
