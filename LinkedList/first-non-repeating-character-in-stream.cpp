// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string A)
    {

        string ans;

        unordered_map<char, bool> um;
        unordered_map<char, bool> um2;

        int i = 0, j = 0;
        for (i = 0; i < A.length(); i++)
        {
            if (!um[A[i]])
            {
                um[A[i]] = true;
                um2[A[i]] = true;
            }
            else
            {
                um2[A[i]] = false;
            }

            while (j <= i)
            {
                if ((um[A[j]]) && (um2[A[j]]))
                {
                    ans = ans + A[j];
                    break;
                }
                j++;
            }

            if (i < j)
            {
                ans.append("#");
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

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends