d[0][0] = v[0][0];

// making difference Array
for (j = 1; j < m; j++)
    d[0][j] = v[0][j] - v[0][j - 1];

for (j = 1; j < n; j++)
    d[j][0] = v[j][0] - v[j - 1][0];

for (i = 1; i < n; i++)
{
    for (j = 1; j < m; j++)
        d[i][j] = v[i][j] - v[i][j - 1] - v[i - 1][j] + v[i - 1][j - 1];
}

// Modifications
while (u--)
{
    cin >> k >> p >> q >> a >> b;

    d[p][q] += k;

    if (a + 1 < n)
        d[a + 1][q] -= k;

    if (b + 1 < m)
        d[p][b + 1] -= k;

    if ((a + 1 < n) && (b + 1 < m))
        d[a + 1][b + 1] += k;
}

// Regaining Array from Difference Array
for (j = 1; j < m; j++)
    d[0][j] = d[0][j] + d[0][j - 1];

for (j = 1; j < n; j++)
    d[j][0] = d[j][0] + d[j - 1][0];

for (i = 1; i < n; i++)
{
    for (j = 1; j < m; j++)
        d[i][j] = d[i][j] + d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1];
}
