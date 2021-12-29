#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void countingSort(int a[], int n, int place)
    {
        int count[10];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < n; i++)
        {
            int countIndex = (a[i] / place) % 10;
            count[countIndex]++;
        }

        // making prefix-sum-array of count
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        int output[n];

        for (int i = 0; i < n; i++)
        {
            int countIndex = (a[i] / place) % 10;
            output[--count[countIndex]] = a[i];
        }

        for (int i = 0; i < n; i++)
            a[i] = output[i];
    }

    void radixSort(int a[], int n)
    {
        
        
        // if d be the digits of maxElement
        // time complexity will be O(d*(n+b)) = O(( logb(k) )*(n+b))
        // where b is the base of number system, here 10
        
        
        
        int maxElement = *max_element(a, a + n);

        for (int place = 1; (maxElement / place) > 0; place *= 10)
        {
            countingSort(a, n, place);

            for (auto x = 0; x < n; x++)
                cout << a[x] << " ";
            cout << endl;
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

        obj.radixSort(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
}
