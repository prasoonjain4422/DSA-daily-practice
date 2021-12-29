#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
};

class Solution
{
public:
    Node *buildList(int n)
    {

        if (n == 0)
            return NULL;

        int currData;

        cin >> currData;
        Node *root = new Node;
        root->data = currData;
        Node *temp = root;

        for (int i = 1; i < n; i++)
        {
            cin >> currData;

            temp->next = new Node();
            temp = temp->next;
            temp->data = currData;
        }

        return root;
    }

    void printList(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        printList(root->next);
    }

    Node *reverseList(Node *root, int k)
    {

        if ((root == NULL) || (root->next == NULL))
            return root;

        Node *firstNode = root;
        Node *pre = NULL;
        Node *cur = root;
        Node *nxt = root->next;

        int i = k - 1;

        while ((nxt != NULL) && (i--))
        {
            cur->next = pre;
            pre = cur;
            cur = nxt;

            nxt = nxt->next;
        }

        cur->next = pre;

        firstNode->next = reverseList(nxt, k);

        return cur;
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, n, k;

    Solution obj;

    cin >> t;
    while (t--)
    {
        // number of Nodes
        cin >> n >> k;

        Node *root = obj.buildList(n);

        obj.printList(root);
        cout << endl;

        root = obj.reverseList(root, k);

        obj.printList(root);
    }

    return 0;
}
