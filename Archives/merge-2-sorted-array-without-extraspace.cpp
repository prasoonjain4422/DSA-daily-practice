#include <bits/stdc++.h>
using namespace std;

// brute force will be
// choose smallest elements of b
// and insert them in correct place in a
// O(n*m)

class Solution
{
public:
    // Efficient
    void merge(vector<int> &a, vector<int> &b)
    {
        // O(nlogn + mlogm + n + m)

        int n = a.size();
        int m = b.size();
        int i, j, k;

        i = 0;
        j = 0;
        k = n - 1;

        while ((i <= k) && (j < m))
        {
            if (a[i] > b[j])
            {
                swap(a[k], b[j]);
                j++;
                k--;
            }
            else
            {
                i++;
            }
        }

        sort(a.begin(), a.end()); //    O(nlogn)
        sort(b.begin(), b.end()); //    O(mlogm)
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);

        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        Solution obj;

        // merging two sorted arrays
        obj.merge(a, b);
        // now they are in order = a, b
    }

    return 0;
}
