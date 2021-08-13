#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n = 18;
        int i = log2(n);
        
        while(n>0)
        {
            cout<<n<<endl;
            i = log2(n);
            n = n&(~(1<<i));
        }
        
    }
    return 0;
}
