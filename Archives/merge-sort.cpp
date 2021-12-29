#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(int a[], int low, int mid, int high)
    {

        // O(n)
        int leftSubSize = mid - low + 1;
        int rightSubSize = high - mid;

        int leftSubArray[leftSubSize];
        int rightSubArray[rightSubSize];

        int i, j, k;

        for (i = 0; i < leftSubSize; i++)
        {
            leftSubArray[i] = a[low + i];
        }

        for (i = 0; i < rightSubSize; i++)
        {
            rightSubArray[i] = a[mid + 1 + i];
        }

        i = 0;
        j = 0;
        k = low;

        while ((i < leftSubSize) && (j < rightSubSize))
        {
            if (leftSubArray[i] < rightSubArray[j])
            {
                a[k] = leftSubArray[i];
                i++;
                k++;
            }
            else
            {
                a[k] = rightSubArray[j];
                j++;
                k++;
            }
        }

        while (i < leftSubSize)
        {
            a[k] = leftSubArray[i];
            i++;
            k++;
        }

        while (j < rightSubSize)
        {

            a[k] = rightSubArray[j];
            j++;
            k++;
        }
    }

    void mergeSort(int a[], int low, int high)
    {

        // O(log n)
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergeSort(a, low, mid);
            mergeSort(a, mid + 1, high);
            merge(a, low, mid, high);
        }
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

        // O(n logn)
        obj.mergeSort(a, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
}
