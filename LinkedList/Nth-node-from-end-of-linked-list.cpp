// { Driver Code Starts
//Initial Template for C
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} * start;

void insert();

// } Driver Code Ends
//User function Template for C
//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(struct Node *head, int n)
{

    if ((head->next == NULL))
        return (head->data);

    struct Node *nex = head->next;
    struct Node *cur = head;
    struct Node *pre = NULL;

    int i = 1;
    while (nex != NULL)
    {
        i++;
        cur->next = pre;
        pre = cur;
        cur = nex;
        nex = nex->next;
    }
    cur->next = pre;

    if (n > i)
    {
        return (int)(-1);
    }

    n--;
    while (n--)
    {
        cur = cur->next;
    }

    return (cur->data);
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        start = NULL;
        int n, k;
        scanf("%d", &n);
        scanf("%d", &k);
        insert(n);
        int res = getNthFromLast(start, k);
        printf("%d\n", res);
    }
    return 0;
}

void insert(int n)
{
    int value, i;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (i == 0)
        {
            start = (struct Node *)malloc(sizeof(struct Node));
            start->data = value;
            start->next = NULL;
            temp = start;
            continue;
        }
        else
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
}

// } Driver Code Ends