#include <bits/stdc++.h>
#define ll long long int
#define endl "\n";
using namespace std;
ll n, i, j;
string aset;

void subsets()
{
    cout << "---" << endl;
    for (i = 1; i < (1 << n); i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i & (1 << j))
                cout << aset[j];
        }
        cout << endl;
    }
}

int main()
{
    cin >> aset;
    n = aset.length();
    subsets();

    return 0;
}
