// { Driver Code Starts
// driver

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
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
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    //Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        stack<int> s1, s2;

        while (first != NULL)
        {
            s1.push(first->data);
            first = first->next;
        }

        while (second != NULL)
        {
            s2.push(second->data);
            second = second->next;
        }

        int carry = 0, total = 0;
        Node *cur = NULL, *pre = NULL;
        while ((!s1.empty()) && (!s2.empty()))
        {
            total = s1.top() + s2.top() + carry;
            cur = new Node(total % 10);
            cur->next = pre;
            pre = cur;
            carry = total / 10;
            s1.pop();
            s2.pop();
        }
        while (!s1.empty())
        {
            total = s1.top() + carry;
            cur = new Node(total % 10);
            cur->next = pre;
            pre = cur;
            carry = total / 10;
            s1.pop();
        }
        while (!s2.empty())
        {
            total = s2.top() + carry;
            cur = new Node(total % 10);
            cur->next = pre;
            pre = cur;
            carry = total / 10;
            s2.pop();
        }
        while (carry > 0)
        {
            cur = new Node(carry % 10);
            cur->next = pre;
            pre = cur;
            carry = carry / 10;
        }

        // while(cur!=NULL)
        // {
        //     cout<<(cur->data)<<" ";
        //     cur = cur->next;
        // }

        return cur;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends