// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int a[], int n)
    {
        int i, ac = 0, bc = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] == 0)
                ac++;
            else if (a[i] == 1)
                bc++;
            else
            {
            }
        }
        for (i = 0; i < ac; i++)
        {
            a[i] = 0;
        }

        for (i; i < (ac + bc); i++)
        {
            a[i] = 1;
        }

        for (i; i < n; i++)
        {
            a[i] = 2;
        }
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}
