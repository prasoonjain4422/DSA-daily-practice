// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    void mul(int i, vector<int> &ans)
    {
        int carry = 0;
        int pro = 1;

        for (auto it = ans.begin(); it != ans.end(); it++)
        {
            pro = (*it) * i + carry;
            (*it) = pro % 10;
            carry = pro / 10;
        }

        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }

    vector<int> factorial(int N)
    {

        int i = 2;
        vector<int> ans;
        ans.push_back(1);

        for (i = 2; i <= N; i++)
            mul(i, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends