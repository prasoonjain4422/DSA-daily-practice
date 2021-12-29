#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void heapify(int a[], int i, int n)
    {

        int largest = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < n)
        {
            if (a[largest] < a[leftChild])
            {
                largest = leftChild;
            }
        }

        if (rightChild < n)
        {
            if (a[largest] < a[rightChild])
            {
                largest = rightChild;
            }
        }

        if (largest != i)
        {
            swap(a[largest], a[i]);
            heapify(a, largest, n);
        }
    }

    void buildHeap(int a[], int n)
    {
        // for building max heap - means parent will have grearter value than its children

        int halfSize = (n / 2) - 1;

        for (int i = halfSize; i >= 0; i--)
        {
            heapify(a, i, n);
        }
    }

    void heapSort(int a[], int n)
    {
        buildHeap(a, n);

        int lastElement = n - 1;

        for (int i = lastElement; i > 0; i--)
        {
            swap(a[0], a[i]);
            heapify(a, 0, i);
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

        obj.heapSort(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
}
