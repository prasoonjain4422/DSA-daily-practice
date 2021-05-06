// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    int trappingWater(int a[], int n)
    {

        int j = a[0], k = a[n - 1], ans = 0;
        int i = 1, e = n - 2, num, it;

        while (i <= e)
        {
            if (j < k)
            {
                if (a[i] < j)
                {
                    ans += j - a[i];
                }
                else if (a[i] > j)
                {
                    j = a[i];
                }
                i++;
            }
            else
            {
                if (a[e] < k)
                {
                    ans += k - a[e];
                }
                else if (a[e] > k)
                {
                    k = a[e];
                }
                e--;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends