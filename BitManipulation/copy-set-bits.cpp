
// Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. The
// task is consider set bits of y in range [l, r] and set these bits in x also.

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int x, y, i, j, r, l;
    cin >> x >> y;
    cin >> r >> l;

    int masklength = (1 << ((r - l + 1) - 1));
    
    int mask = ((masklength)<<(l-1));
    
    mask = y & mask;
    
    x = x | mask;
    
    cout<<x;
}
