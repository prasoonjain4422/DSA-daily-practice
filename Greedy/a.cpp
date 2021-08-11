// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    char b, c = 'a';

    cout << c;
    c++;
    cout << c;
    b = c + 3;
    cout << b;
    cout << endl;

    for (b; b >= 'a'; b--)
    {
        cout << b;
    }

    return 0;
}
