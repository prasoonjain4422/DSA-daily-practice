#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;;
    Node *parent;
};

int fun(Node *a, Node *b)
{
    unordered_set<Node*> v;
    while(a != NULL)
    {
        if(a == b)
        {
            return v.size();
        }
        
        v.insert(a);
        a = a->parent;
    }
    
    int i=0;
    while(b != NULL)
    {        
        if(v.find(b) == v.end())
        {
            i++;
            b = b->parent;
        }
        else
        {
            return (distance(v.begin(), v.find(b)) + i);
        }
    }
    
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, i, k;
        cin >> n >> k;
        vector<int> a(n);

        for (i = 0; i < n; i++)
            cin >> a[i];

    }
    return 0;
}
