#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

int table[MAX_N][25];
int logg[MAX_N];

class SparseTable
{
public:
    SparseTable(vector<int> data);
    int query(int L, int R);
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> v = {1, 2, -4, 6, 10, -8};

    SparseTable obj(v);

    cout << obj.query(0, 3);
    return 0;
}

void build(vector<int> &data)
{
    int n = data.size();
    int L, R, W;

    for (L = n - 1; L >= 0; L--)
    {
        for (W = 0; W < 25; W++)
        {
            R = L + (1 << W) - 1;
            if (R >= n)
                break;

            if (W == 0)
                table[L][W] = data[L];
            else
                table[L][W] = min(table[L][W - 1], table[L + (1 << (W - 1))][W - 1]);
        }
    }
}

int query(int L, int R)
{
    int W = R - L;
    // int power = W;
    int power = logg[W];
    return min(table[L][1 << power], table[R - (1 << power)][1 << power]);
}

void build_log(int N)
{
    logg[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        logg[i] = i + logg[i / 2];
    }
}
