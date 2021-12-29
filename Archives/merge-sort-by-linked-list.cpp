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

    Node *merge(Node *firstList, Node *secondList)
    {

        if (firstList == NULL)
            return secondList;

        if (secondList == NULL)
            return firstList;

        if (firstList->data > secondList->data)
        {
            secondList->next = merge(firstList, secondList->next);
            return secondList;
        }

        firstList->next = merge(firstList->next, secondList);
        return firstList;
    }

    Node *mergeSortList(Node *root)
    {

        if ((root == NULL) || (root->next == NULL))
            return root;

        Node *fast = root;
        Node *slow = root;

        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        // cout << slow->data << " ";

        // n    fast    slow
        // 2    2       1
        // 3    3       2
        // 4    4       2
        // 5    5       3
        // 6    6       3

        Node *secondList = slow->next;
        secondList = mergeSortList(secondList);

        slow->next = NULL;
        root = mergeSortList(root);

        return merge(root, secondList);
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

        root = obj.mergeSortList(root);

        obj.printList(root);
    }

    return 0;
}
