#include <bits/stdc++.h>

// A linked list node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void append(struct Node **head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    struct Node *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so
		make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
		node as head */
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}

// } Driver Code Ends
//User function Template for C

void swap(struct Node *head, struct Node *next, struct Node *prev)
{
    head->next = prev;
    head->prev = next;
}

struct Node *rotateDLL(struct Node *head, int r)
{
    
    // input  -> 1 2 3 4 5,  r=2
    // output -> 3 4 5 1 2

    if ((head == NULL) || (head->next == NULL))
        return head;

    Node *s = head, *cur = head;
    r--;
    while (r--)
    {
        cur = cur->next;
    }
    
    Node *a = cur->next;
    cur->next = NULL;

    cur = a;
    cur->prev = NULL;

    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    
    cur->next = head;
    head->prev = cur;

    return a;
}

// { Driver Code Starts.

void displayList(struct Node *node)
{
    struct Node *last;
    while (node != NULL)
    {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t;
    scanf("%d", &t);
    while (t--)
    {
        struct Node *head = NULL;
        int n, r;
        scanf("%d %d", &n, &r);
        for (int i = 0; i < n; i++)
        {
            int k;
            scanf("%d", &k);
            append(&head, k);
        }
        head = rotateDLL(head, r);
        displayList(head);
        printf("\n");
    }
    return 0;
}
