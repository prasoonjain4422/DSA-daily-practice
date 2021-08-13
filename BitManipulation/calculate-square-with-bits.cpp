#include <bits/stdc++.h>
using namespace std;

// square(n) = 0 if n == 0
//   if n is even 
//      square(n) = 4*square(n/2) 
//   if n is odd
//      square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 


int square(int n)
{
    
    if(n == 0)
        return 0;
    
    int x = n>>1;
    
    if(n&1)
    {
        return ((square(x)<<2) + (x<<2) + (1));
    }
    else
    {
        return (square(x)<<2);
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    long long i, j, n, ans = 0;
    cin>>n;
    
    cout<<square(n);
    return 0;
}
