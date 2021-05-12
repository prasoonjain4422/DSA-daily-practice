// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

// } Driver Code Ends
/*
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
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {

        if ((head == NULL) || (head->next == NULL))
            return true;

        // First reversing

        Node *cur = head, *n;
        Node *rev = new Node(head->data);

        while (cur->next != NULL)
        {
            cur = cur->next;
            n = new Node(cur->data);
            n->next = rev;
            rev = n;
        }

        while (head != NULL)
        {
            if (head->data != rev->data)
            {
                return false;
            }
            head = head->next;
            rev = rev->next;
        }

        return true;
        ;
    }
};

// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends