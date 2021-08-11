// map<int, int> hm;
// for (int i = 0; i < n; i++)
//     hm[in[i]] = i;
// printPost(in, pre, 0, n - 1, hm);

// Result ans;
// for(int i=0; i<n; i++)
// {
//     ans.output1[i] = ans2[i];
// }
// return ans;
#include <bits/stdc++.h>
using namespace std;
int h, a;
int dp[1000][1000][3];

int ans2[100];
int ansind = 0;

int preIndex = 0;
void printPost(int in[], int pre[], int inStrt, int inEnd, map<int, int> hm)
{
    if (inStrt > inEnd)
        return;

    int inIndex = hm[pre[preIndex++]];

    printPost(in, pre, inStrt, inIndex - 1, hm);

    printPost(in, pre, inIndex + 1, inEnd, hm);

    ans2[ansind++] = in[inIndex];
}

struct Result
{
    Result() : output1(){};
    int output1[100];
};

struct Result Find_PostOrder(int in[], int pre[], int n)
{
}
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

int main()
{


    int i, j, n, q;
    cin >> n;

    vector<string> s(n);

    for (i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    cin >> q;

    while (q--)
    {
        cin >> j;

        if (j == 1)
        {
            cout << s[n - 1] << " ";
        }
        else if (j == 2)
        {
            cout << s[0] << " ";
        }
        else if (j == 3)
        {
            cout << s[1] << " ";
        }
        else if (j == 4)
        {
            cout << s[n - 2] << " ";
        }
        else
        {
            reverse(s[0].begin(), s[0].end());
            cout << s[0] << " ";
        }
    }

    return 0;
}
