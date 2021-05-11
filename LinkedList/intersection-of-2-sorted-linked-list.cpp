// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Node *result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node *findIntersection(Node *head1, Node *head2)
{
    unordered_set<int> s;

    while (head1 != NULL)
    {
        s.insert(head1->data);
    }

    Node *ans = NULL, *it = NULL;

    if (head2 != NULL)
    {
        if (s.find(head2->data) == s.end())
        {
            head2 = head2->next;
            if (head2 == NULL)
                return NULL;
        }

        ans = head2;
        it = head2;
        head2 = head2->next;

        while (head2 != NULL)
        {
            if (s.find(head2->data) != s.end())
            {
                it->next = head2;
                it = it->next;
            }

            head2 = head2->next;
        }

        it->next = NULL;
    }

    return ans;
}
