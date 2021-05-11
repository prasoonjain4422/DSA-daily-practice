

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *addOne(Node *head)
    {
        Node *cur = head;
        Node *b = head;

        if (cur == NULL)
        {
            return cur;
        }

        if (cur->next == NULL)
        {
            cur->data = cur->data + 1;
            return head;
        }

        while (cur->next != NULL)
        {
            if ((cur->data != 9) && (cur->next->data == 9))
                b = cur;

            cur = cur->next;
        }

        if (cur->data == 9)
        {
            b->data = b->data + 1;
            b = b->next;

            while (b != NULL)
            {
                b->data = 0;
                b = b->next;
            }
        }
        else
        {
            cur->data = cur->data + 1;
        }

        return head;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends