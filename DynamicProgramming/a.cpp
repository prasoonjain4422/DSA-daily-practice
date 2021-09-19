#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int i, j, n;
    
    cin>>n;
    int a[n], b[n];
    
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    
    sort(a, a+n);
    
    int ans = 0;
    for(i=0; i<n; i++)
    {
        if(a[i] != b[i])
            ans++;
    }
    
    if(ans > 2)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }
    
    return 0;
}