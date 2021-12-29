#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partition(int a[], int low, int high)
    {
        if (low == high)
        {
            return low;
        }

        int pivot = high;

        int j = low - 1;
        for (int i = low; i < high; i++)
        {
            if (a[i] < a[pivot])
            {
                j++;

                if (i != j)
                {
                    swap(a[j], a[i]);
                }
            }
        }

        swap(a[j + 1], a[pivot]);

        return (j + 1);
    }
    void quickSort(int a[], int low, int high)
    {
        cout << "here " << low << " " << high << endl;
        if (low < high)
        {
            int p = partition(a, low, high);
            quickSort(a, low, p - 1);
            quickSort(a, p + 1, high);
        }
        return;
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

        // obj.quickSort(a, n);
        obj.quickSort(a, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
}
