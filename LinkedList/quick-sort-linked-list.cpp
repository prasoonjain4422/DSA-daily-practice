// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;

/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node **head_ref, int new_data)
{
    /* allocate node */
    struct node *new_node = new node(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
    int t, n, x;
    cin >> t;
    while (t--)
    {

        cin >> n;
        n = n - 1;
        cin >> x;
        node *temp, *head = new node(x);
        temp = head;
        while (n--)
        {
            cin >> x;
            temp->next = new node(x);
            temp = temp->next;
        }

        quickSort(&head);

        printList(head);
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    return 0;
} // } Driver Code Ends

/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function

node *partition(struct node *head)
{
    if ((head == NULL) || (head->next == NULL))
        return head;

    node *end = head, *i = new node(0);
    i->next = head;

    while (end->next != NULL)
        end = end->next;

    while (head != end)
    {
        if (((head->data) <= (end->data)) && (head != i))
        {
            i = i->next;
            swap((i->data), (head->data));
        }
        head = head->next;
    }
    swap((i->next->data), (end->data));

    return i;
}

void quickSort(struct node **headRef)
{

    if (headRef == NULL)
        return;

    node *head = *headRef;

    if ((head == NULL) || (head->next == NULL))
        return;

    node *a = partition(head);

    if (a->next != NULL)
    {
        node *b = a->next;
        quickSort(&(a->next->next));
        a->next = NULL;
        quickSort(&(head));
        a->next = b;
    }
    else
    {
        quickSort(&(head));
    }
}
