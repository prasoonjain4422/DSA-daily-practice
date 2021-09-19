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
    vector<int> a(n);
    
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    
    int ans = 0;
    for(i=1; i<n-1; i++)
    {
        if((a[i] > a[i-1])&&(a[i] <= a[i+1]))
        {
            ans++;
        }
        else if((a[i] > a[i+1])&&(a[i] <= a[i-1]))
        {
            ans++;
        }
    }
    
    cout<<ans;
    
    return 0;
}