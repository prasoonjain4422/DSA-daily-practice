#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void countingSort(int a[], int n)
    {
        // O(n + range)

        // when range will dominate n the algoithm
        // will not be having linear time complexity anymore

        int minElement = *min_element(a, a + n);
        int maxElement = *max_element(a, a + n);

        int range = maxElement - minElement + 1;

        int count[range];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < n; i++)
        {
            int countIndex = a[i] - minElement;
            count[countIndex]++;
        }

        // making prefix-sum-array of count
        for (int i = 1; i < range; i++)
        {
            count[i] += count[i - 1];
        }

        int b[n];

        for (int i = 0; i < n; i++)
        {
            int countIndex = a[i] - minElement;
            b[--count[countIndex]] = a[i];
        }

        for (int i = 0; i < n; i++)
            a[i] = b[i];
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    Solution obj;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];

        obj.countingSort(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
}
