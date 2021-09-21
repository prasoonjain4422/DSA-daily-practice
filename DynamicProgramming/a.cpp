#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {

        int i, j, n = str.size();
        int maxn, ind;
        unordered_map<int, int> sp; //swap-pairs

        for (i = 0; i < n; i++)
        {
            sp[i] = i;
        }

        for (i = 0; i < n; i++)
        {
            maxn = str[i] - 48, ind;
            for (j = n - 1; j > i; j--)
            {
                if ((str[j] - 48) > maxn)
                {
                    maxn = str[j] - 48;
                    ind = j;
                }
            }

            if (maxn != (str[i] - 48))
            {
                k--;
                swap(str[i], str[ind]);

                sp[i] = ind;

                if (k == 0)
                    break;
            }
        }

        int mi;
        cout << str << endl;
        for (i; i > 0; i--)
        {
            j = i;
            while ((j > 0) && (str[i] == str[j - 1]))
                j--;

            if (i > j)
            {
                multiset<int, greater<int>> temp;
                set<int> po;
                mi = j;

                cout << "out  " << j << endl;
                for (j; j <= i; j++)
                {
                    cout << "dfkh  " << j << endl;
                    int a = j;

                    if (sp[a] != a)
                    {
                        while (sp[a] != a)
                        {
                            a = sp[a];
                        }

                        po.insert(a);
                        temp.insert(str[a] - 48);
                    }
                }

                auto it2 = temp.begin();
                for (auto it = po.begin(); it != po.end(); it++)
                {
                    str[*it] = *it2 + 48;
                    it2++;
                }
            }

            i = mi;
        }
        cout << "dfkh" << endl;
        return str;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
