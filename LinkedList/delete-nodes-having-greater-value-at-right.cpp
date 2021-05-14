// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *compute(Node *head)
    {

        if ((head == NULL) || (head->next == NULL))
            return head;

        Node *nex = head->next;
        Node *cur = head;
        Node *pre = NULL;

        while (nex != NULL)
        {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        cur->next = pre;

        int i = cur->data;

        Node *root = cur;
        nex = cur->next;
        pre = NULL;

        while (nex != NULL)
        {
            while ((nex->data) < (i))
            {
                nex = nex->next;
                if (nex == NULL)
                    break;
            }

            cur->next = nex;

            if (nex == NULL)
                break;

            nex = nex->next;
            cur = cur->next;
            i = max(i, cur->data);
        }

        cur = root;
        nex = cur->next;
        pre = NULL;
        while (nex != NULL)
        {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        cur->next = pre;

        return cur;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}
// } Driver Code Ends