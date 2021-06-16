#include <bits/stdc++.h>
using namespace std;

string a;
const int M = 1000000007;
long long int dp[1000][1000];
class Solution
{
public:
    string lpsub(string &s, int i, int j)
    {
        
    }
};
        
        

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
        cout << ob.lpsub(str) << endl;
    }
}
