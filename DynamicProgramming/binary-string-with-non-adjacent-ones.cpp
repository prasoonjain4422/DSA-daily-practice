#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
    int i;
    int dpz[n+1], dpo[n+1];
    
    dpz[1] = 1, dpo[1] = 1;
    dpz[2] = 2, dpo[2] = 1;
    
    for(i=3; i<=n; i++)
    {
        
        dpz[i] = dpz[i-1] + dpo[i-1];
        dpo[i] = dpz[i-1];
    }
    
    return dpz[n] + dpo[n];
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, t, c, i, u, v, j;
    cin >> n;
    cout << fun(n) << endl;

    return 0;
}