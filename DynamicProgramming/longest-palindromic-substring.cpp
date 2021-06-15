#include <bits/stdc++.h>
using namespace std;

//largest palindromic subsequence

long long int dp[1000][1000];
string ans;

// int lpsutil(string s, int i, int j)
// {

//     if(i>j)
//         return 0;

//     if(i==j)
//         return 1;

//     if(s[i] == s[j])
//     {
//         dp[i][j] = lpsutil(s, i+1, j-1);
//     }
//     else
//     {
//     }


// }

int lps(string s, int i, int j)
{

    if (i > j)
        return 0;

    if (i == j)
        return 1;
    
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    
    if(s[i] == s[j])
    {
        dp[i][j] = lps(s, i+1, j-1)
    }
    
    
    
    
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        memset(dp, -1, sizeof(dp));
        getline(cin, s);
        ans = "";
        int n = 0;
        n = s.length();
        cout << lps(s, 0, n - 1) << endl;
    }
    return 0;
}
