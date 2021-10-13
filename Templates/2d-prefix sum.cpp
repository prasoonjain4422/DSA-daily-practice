
// v[][] is the original array
// dp[][] is the prefix sum array

dp[0][0] = v[0][0];
for (j = 1; j < m; j++)
    dp[0][j] = v[0][j] + dp[0][j - 1];

for (j = 1; j < n; j++)
    dp[j][0] = v[j][0] + dp[j - 1][0];

for (i = 1; i < n; i++)
{
    for (j = 1; j < m; j++)
        dp[i][j] = v[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
}
