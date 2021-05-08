// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;

int minSwap(int *arr, int n, int k);

// Driver code
int main()
{

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        cout << minSwap(arr, n, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends

int minSwap(int a[], int n, int k)
{
    
    // sliding window algorithm

    int i, j, c = 0, ans = 0, ans2 = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] <= k)
            c++;
    }

    for (i = 0; i < c; i++)
    {
        if (a[i] > k)
            ans++;
    }

    if (ans == 0)
        return ans;

    ans2 = ans;
    for (i = 0, j = c; j < n; i++, j++)
    {
        if (a[i] > k)
            ans--;

        if (a[j] > k)
            ans++;

        ans2 = min(ans2, ans);
    }

    return ans2;
}
