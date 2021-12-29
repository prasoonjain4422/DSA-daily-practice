#include <bits/stdc++.h>
using namespace std;

// brute force will be finding all permutations
// and store them in sorted order and give output
// the next permutation of input

class Solution
{
public:
    string nextPermutation(string &s)
    {
        // O(nlogn)

        int n = s.size();
        int nextIndex = n - 1;

        vector<char> mm;
        mm.push_back(s[nextIndex]); //  last Index

        for (int i = nextIndex - 1; i >= 0; i--)
        {
            // O(n)
            if (s[i] > s[nextIndex])
            {
                mm.push_back(s[i]);
                nextIndex--;
            }
            else
            {
                char currChar = s[i];

                auto it = (upper_bound(mm.begin(), mm.end(), currChar) - mm.begin());

                // cout << it << endl;

                s[i] = mm[it];
                i++;

                mm[it] = currChar;
                
                // O(nlogn)
                sort(mm.begin(), mm.end());
                
                for (auto x : mm)
                {
                    s[i] = x;
                    i++;
                }

                break;
            }
        }

        return s;
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
        // int n, i;
        string s;
        cin >> s;

        cout << obj.nextPermutation(s);
    }

    return 0;
}
