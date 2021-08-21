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

    int i, j, n, s, sum, ans=INT_MAX;
    cin>>n;
    vector<int> a(n);
    for(i=0; i<n; i++)
        cin>>a[i];
    
    cin>>s;
    int m, l=0, r = INT_MAX;
    while(l<=r)
    {
        m = (l+r)/2;
        sum = 0;
        for(i=0; i<n; i++)
            sum += max(a[i]-m, 0);
        
        if(sum > s)
        {
            l = m+1;
        }
        else
        {
            r = m-1;
            ans = min(ans, m);
        }
    }
    cout<<ans;    
    return 0;
}
