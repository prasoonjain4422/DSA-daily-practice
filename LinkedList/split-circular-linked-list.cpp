// { Driver Code Starts
/* Program to split a circular linked list into two halves */
#include <stdio.h>
#include <stdlib.h>

/* structure for a Node */
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

void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref);
struct Node *newNode(int key)
{
    struct Node *temp = new Node(key);

    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of 
    the two resultant linked lists */

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

/* Driver program to test above functions */
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n, i, x;
    scanf("%d", &t);
    while (t--)
    {
        struct Node *temp, *head = NULL;
        struct Node *head1 = NULL;
        struct Node *head2 = NULL;
        scanf("%d", &n);
        scanf("%d", &x);
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++)
        {
            scanf("%d", &x);

            temp->next = new Node(x);

            temp = temp->next;
        }

        temp->next = head;

        splitList(head, &head1, &head2);

        //   printList(head1);
        // printf("\nFirst Circular Linked List");
        //   printList(head2);

        // printf("\nSecond Circular Linked List");
    }
    return 0;
}
// } Driver Code Ends

/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{

    Node *fast = head;
    Node *slow = head;

    // fast = fast->next;
    // slow = slow->next;

    while (fast->next != head)
    {
        fast = fast->next;
        if (fast->next != head)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
    // head2_ref = &(slow->next);

    Node *slo = slow->next;
    slow->next = NULL;

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");

    while (slo != NULL)
    {
        printf("%d ", slo->data);
        slo = slo->next;
    }

    // head1_ref = &head;
}