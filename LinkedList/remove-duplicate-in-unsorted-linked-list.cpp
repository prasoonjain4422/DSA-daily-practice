// { Driver Code Starts
using namespace std;
#include <bits/stdc++.h>

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

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        unordered_set<int> s;

        if (head == NULL)
            return head;

        s.insert(head->data);
        Node *cur = head;
        Node *nex = head->next;

        while (nex != NULL)
        {
            while (s.find(nex->data) != s.end())
            {
                nex = nex->next;
                if (nex == NULL)
                    break;
            }
            cur->next = nex;
            cur = nex;

            if (nex == NULL)
                break;

            s.insert(nex->data);
            nex = nex->next;
        }

        return head;
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
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
        Node *result = ob.removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends