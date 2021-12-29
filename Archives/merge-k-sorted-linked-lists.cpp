#include <bits/stdc++.h>
using namespace std;

// Brute force solution can be that we will
// first merge all linked lists and
// then we can sort the resulting linked list.
// Time complexity for this approach will be
// O(n) for merging + O(n*logn) for sorting = O(n*logn)



// Efficient approach is to use min heap.
// Time complexity for this approach will be
// O(n*k*logk)

struct Node
{
    int data;
    Node *next = NULL;
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k, l, m;

    //  n - number of nodes in a linked list
    cin >> n >> k;

    vector<Node *> lls(k);

    //  taking input
    for (i = 0; i < k; i++)
    {
        struct Node *root = new Node();
        lls[i] = root;
        for (j = 1; j < n; j++)
        {
            cin >> l;
            root->data = l;
            root->next = new Node();
            root = root->next;
        }
        cin >> l;
        root->data = l;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    for (i = 0; i < k; i++)
    {
        min_heap.push({lls[i]->data, i});
        // cout << lls[i]->data << " " << i << endl;
        lls[i] = lls[i]->next;
    }

    Node *ans = new Node();
    Node *root = ans;

    while (min_heap.size() > 1)
    {
        i = min_heap.top().first;
        j = min_heap.top().second;
        cout << i << " " << j << endl;
        min_heap.pop();

        root->data = i;
        root->next = new Node();
        root = root->next;

        if (lls[j] != NULL)
        {
            min_heap.push({lls[j]->data, j});
            lls[j] = lls[j]->next;
        }
    }

    root->data = min_heap.top().first;

    cout << endl;
    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}



