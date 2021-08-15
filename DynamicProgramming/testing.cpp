#include <bits/stdc++.h>
using namespace std;

int countFreq(string &pat, string &txt)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        /* For current index i, check for
           pattern match */
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M)
        {
            res++;
            j = 0;
        }
    }
    return res;
}

void computeLPSArray(string pat, int M,
                     int lps[])
{
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = len;
                i++;
            }
        }
    }
}

int KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
    int lps[M];
    int j = 0;

    computeLPSArray(pat, M, lps);

    int i = 0;
    int res = 0;
    int next_i = 0;

    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            j = lps[j - 1];
            res++;
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j;
    string s, e;
    int n, ans = 0, q, m, p;
    unordered_map<string, bool> um;

    cin >> s;
    cin >> q;

    n = s.length();

    while (q--)
    {
        cin >> m >> p;
        ans = 0;

        um.clear();
        for (i = 0; (i + m) <= n; i++)
        {
            e = s.substr(i, m);
            if (!um[e])
            {
                um[e] = true;
                cout << s << " " << e << endl;
                cout << i << "  " << countFreq(s, e) << endl;
                if (p == countFreq(s, e))
                    ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
