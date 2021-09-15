#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, n, k, d = 0;

    cin >> n;
    
    int dpmw[n+1], dpwm[n+1], dpww[n+1], dpt[n+1];
    
    dpmw[1] = 1;
    dpwm[1] = 1;
    dpww[1] = 1;
    dpt[1] = 3;
    
    for(i=2; i<=n; i++)
    {
        
        dpmw[i] = dpwm[i-1] + dpww[i-1];
        dpwm[i] = dpmw[i-1] + dpww[i-1];
        dpww[i] = dpmw[i-1] + dpwm[i-1] + dpww[i-1];
        
        dpt[i] = dpmw[i] + dpwm[i] + dpww[i];
    }
    
    
    cout<<dpt[n];
    
    
    return 0;
}



