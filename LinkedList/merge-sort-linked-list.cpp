// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    //Function to sort the given linked list using Merge Sort.

    Node *merge(Node *a, Node *b)
    {

        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        Node *result = new Node(0);

        if ((a->data) <= (b->data))
        {
            result->data = a->data;
            result->next = merge(a->next, b);
        }
        else
        {
            result->data = b->data;
            result->next = merge(a, b->next);
        }

        return result;
    }

    Node *mergeSort(Node *head)
    {

        if ((head == NULL) || (head->next == NULL))
            return head;

        Node *slow = head, *fast = head;

        fast = fast->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        Node *a = head, *b = slow->next;
        slow->next = NULL;

        a = mergeSort(a);
        b = mergeSort(b);
        Node *result = merge(a, b);

        return result;
    }
};

// { Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
} // } Driver Code Ends