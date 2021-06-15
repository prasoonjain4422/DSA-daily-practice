// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

string a;
const int M = 1000000007;
long long int dp[1000][1000];
class Solution
{
public:
    /*You are required to complete below method */
    void countPS(string &s, int i, int j)
    {

        if (i > j)
            return;

        if (s[i] == s[j])
        {
            a = a + s[i];
            countPS(s, i + 1, j - 1);
            a = a + s[j];
        }
        else
        {
            a = "";
            countPS(s, i + 1, j);
            string b = a;
            a = "";
            countPS(s, i, j - 1);
            if (b.length() > a.length())
            {
                a = b;
            }
        }
        
        return;
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        a = "";
        memset(dp, -1, sizeof(dp));
        Solution ob;
        ob.countPS(str, 0, str.length() - 1);
        cout << a << endl;
    }
} // } Driver Code Ends