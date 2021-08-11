// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:

    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {

        double r1 = (double)a.first / (double)a.second;
        double r2 = (double)b.first / (double)b.second;

        return (r1 > r2);
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {

        int i, j;

        vector<pair<int, int>> v;

        for (i = 0; i < n; i++)
        {
            v.push_back({arr[i].value, arr[i].weight});
        }

        for (i = 0; i < n; i++)
        {
            cout << v[i].first << " " << v[i].second << endl;
        }

        sort(v.begin(), v.end(), cmp);

        double ans = 0.0;
        for (i = 0; i < n; i++)
        {
            if (W >= v[i].second)
            {

                ans = ans + (double)v[i].first;
                W -= v[i].second;
            }
            else
            {
                ans = ans + (double)(((double)v[i].first) * ((double)W)) / ((double)v[i].second);
                break;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends