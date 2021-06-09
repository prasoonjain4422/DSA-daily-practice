// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    
    int i, j, k;
    int dp[n1+1][n2+1][n3+1];
    memset(dp, 0, sizeof(dp));
    
    
    for(i=1; i<=n1; i++)
    {
        for(j=1; j<=n2; j++)
        {
            for(k=1; k<=n3; k++)
            {
                dp[i][j][k] = 0;
                
                if((A[i-1] == B[j-1])&&(A[i-1] == C[k-1]))
                {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else
                {
                    dp[i][j][k] = max(dp[i][j][k-1], max(dp[i][j-1][k], dp[i-1][j][k]));
                }
            }
        }
    }
    
    return dp[n1][n2][n3];
}
