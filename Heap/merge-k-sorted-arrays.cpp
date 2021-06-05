// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Function to merge k sorted arrays.

    void heapify(vector<pair<int, int>> &a, int k, int i)
    {

        int lar = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < k && a[l].first < a[lar].first)
        {
            lar = l;
        }

        if (r < k && a[r].first < a[lar].first)
        {
            lar = r;
        }

        if (i != lar)
        {
            swap(a[i], a[lar]);
            heapify(a, k, lar);
        }
    }

    // O(K*K*logK)

    vector<int> mergeKArrays(vector<vector<int>> a, int k)
    {

        int i;
        vector<int> ans;
        vector<pair<int, int>> heap(k);
        vector<int> ind(k, 1);

        for (i = 0; i < k; i++)
        {
            heap[i] = {a[i][0], i};
        }

        for (i = (k / 2) - 1; i >= 0; i--)
        {
            heapify(heap, k, i);
        }

        while (heap[0].first != INT_MAX)
        {
            ans.push_back(heap[0].first);

            if (ind[heap[0].second] < k)
            {
                heap[0].first = a[heap[0].second][ind[heap[0].second]++];
            }
            else
            {
                heap[0].first = INT_MAX;
            }

            heapify(heap, k, 0);
        }

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
        int k;
        cin >> k;
        vector<vector<int>> arr(N, vector<int>(N, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends