// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct node
{
    int data = 0;
    // char ch;
    node *left = NULL;
    node *right = NULL;

    node(int a)
    {
        data = a;
        // ch = b;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    static void heapify(vector<node *> &pq, int i)
    {

        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int sma = i;

        if (pq[l] < pq[i])
            sma = l;

        if (pq[r] < pq[i])
            sma = r;

        if (sma != i)
        {
            swap(pq[i], pq[sma]);
            heapify(pq, sma);
        }
        
        return;
    }

    static void dfs(node *it, string s, vector<string> &ans)
    {

        if ((it->left == NULL) && (it->right == NULL))
        {
            ans.push_back(s);
            return;
        }

        if (it->left != NULL)
        {
            dfs(it->left, s + "0", ans);
        }

        if (it->right != NULL)
        {
            dfs(it->right, s + "1", ans);
        }

        return;
    }

    vector<string> huffmanCodes(string s, vector<int> f, int n)
    {

        int i, j;
        node *a, *b, *it;

        vector<node *> pq;

        for (i = 0; i < n; i++)
        {
            a = new node(f[i]);
            pq.push_back(a);
        }

        for (i = n / 2 - 1; i >= 0; i--)
            heapify(pq, i);

        while (pq.size() > 1)
        {
            a = *pq.begin();
            pq.erase(pq.begin());

            b = *pq.begin();
            pq.erase(pq.begin());

            cout << "a = " << a->data << endl;
            cout << "b = " << b->data << endl;

            it = new node(a->data + b->data);
            pq.push_back(it);
            // heapify(pq, 0);
        for (i = n / 2 - 1; i >= 0; i--)
            heapify(pq, i);
        }

        it = *pq.begin();
        vector<string> ans;

        dfs(it, "", ans);

        return ans;
    }
};

// { Driver Code Starts.
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
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends
