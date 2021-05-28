#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    ;
    Node *parent;
};

int fun(Node *a, Node *b)
{
    unordered_set<Node *> v;
    while (a != NULL)
    {
        if (a == b)
        {
            return v.size();
        }

        v.insert(a);
        a = a->parent;
    }

    int i = 0;
    while (b != NULL)
    {
        if (v.find(b) == v.end())
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
        int n, i, k, j, s;
        cin >> n;
        i = 1;
        s = 0;
        while (n > (s + pow(26, i)))
        {
            s += pow(26, i);
            i++;
        }

        j = ((n) / pow(26, i - 1));
        if ((n % (int)pow(26, i - 1) == 0) && (i != 1))
        {
            j--;
        }
        while (i--)
        {
            // cout << j << " ";
            char c = (64 + (j));
            cout << c;
            n -= j * pow(26, i);
            j = (n / pow(26, i - 1));
        }

        cout << endl;
    }
    return 0;
}
