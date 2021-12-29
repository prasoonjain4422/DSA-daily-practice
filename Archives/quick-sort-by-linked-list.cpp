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

    pair<Node *, Node *> partition(Node *root)
    {

        cout << "part" << endl;

        if ((root == NULL) || (root->next == NULL))
        {
            return {root, NULL};
        }

        cout << root->data << "- " << endl;

        Node *pivot = root;
        Node *startTraverse = root->next;
        Node *listBefore = NULL;
        Node *listAfter = pivot;
        Node *start = NULL;

        // cout << "part" << endl;
        listAfter->next = NULL;
        while (startTraverse != NULL)
        {

            cout << startTraverse->data << " " << pivot->data << endl;
            if (startTraverse->data < pivot->data)
            {
                if (listBefore == NULL)
                {
                    listBefore = startTraverse;
                    start = listBefore;
                }
                else
                {
                    listBefore->next = startTraverse;
                    listBefore = listBefore->next;
                }
                startTraverse = startTraverse->next;
            }
            else
            {
                // (startTraverse->data >= pivot->data)
                listAfter->next = startTraverse;
                listAfter = listAfter->next;
                startTraverse = startTraverse->next;
                listAfter->next = NULL;
            }

            // cout << startTraverse->data;
            // cout << startTraverse->data;
        }

        if (listBefore == NULL)
        {
            listBefore = pivot;
        }
        else
        {
            listBefore->next = pivot;
        }

        return {start, listBefore}; // node just before the pivot
    }

    Node *quickSortList(Node *root)
    {

        if ((root == NULL) || (root->next == NULL))
        {
            return root;
        }

        cout << "printing  ";
        printList(root);

        cout << endl;
        cout << "qsl" << endl;
        pair<Node *, Node *> dividePoint = partition(root);
        cout << "ap" << endl;

        cout << "After partition  " << endl;
        Node *d = dividePoint.first;
        while (d != NULL)
        {
            cout << d->data << " ";
            d = d->next;
        }
        cout << endl;
        d = dividePoint.second;
        while (d != NULL)
        {
            cout << d->data << " ";
            d = d->next;
        }
        cout << endl;

        if (dividePoint.first == NULL)
        {
            return root;
        }

        Node *beforeList = dividePoint.first;
        Node *afterList = (dividePoint.second->next)->next;
        Node *pivot = dividePoint.second->next;
        dividePoint.second->next = NULL;

        beforeList = quickSortList(beforeList);
        afterList = quickSortList(afterList);

        Node *ans = beforeList;

        while (beforeList->next != NULL)
        {
            beforeList = beforeList->next;
        }

        beforeList->next = pivot;
        pivot->next = afterList;

        return ans;
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
        cin >> n;

        Node *root = obj.buildList(n);

        obj.printList(root);
        cout << endl;

        root = obj.quickSortList(root);

        obj.printList(root);
    }

    return 0;
}
