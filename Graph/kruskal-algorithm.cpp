#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return (a.second <= b.second);
}

int find(vector<int> &parent, int i)
{

    if (parent[i] == -1)
        return i;

    return find(parent, parent[i]);
}

void unionc(vector<int> &parent, int i, int j)
{
    parent[i] = j;
}

vector<pair<pair<int, int>, int>> kruskal(vector<pair<pair<int, int>, int>> &edges, int V)
{

    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(V, -1);
    int i, j, n = 0;
    vector<pair<pair<int, int>, int>> ans;

    for (auto x : edges)
    {
        i = find(parent, x.first.first);
        j = find(parent, x.first.second);

        if (i != j)
        {
            n++;
            ans.push_back(x);
            unionc(parent, i, j);
        }

        if (n == V - 1)
        {
            break;
        }
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<pair<int, int>, int>> av;

        int i, a, b, c;
        for (i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            av.push_back({{a, b}, c});
        }

        av = kruskal(av, n);
        
        for (auto x: av)
        {
            cout<<x.first.first<<" ";
            cout<<x.first.second<<" ";
            cout<<x.second<<endl;
        }
        
    }

    return 0;
}