// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
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

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

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
    //Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int k)
    {

        Node *a = NULL;
        Node *b = NULL;
        Node *c = NULL;

        int i, j, last = k - 1;

        while (last != 0)
        {
            for (i = 0; i < k; i++)
            {
                j = last - i;

                if (i >= j)
                    break;

                if ((arr[i]->data) > (arr[j]->data))
                {
                    c = arr[j];
                    arr[j] = arr[i];
                    arr[i] = c;
                }

                a = arr[i];
                b = arr[j];

                while ((a->next != NULL) && (b != NULL))
                {

                    if ((a->next->data) <= (b->data))
                    {
                        a = a->next;
                    }
                    else
                    {
                        c = a->next;
                        a->next = b;
                        b = b->next;
                        a = a->next;
                        a->next = c;
                    }
                }
                if (b != NULL)
                    a->next = b;
            }

            if (last % 2 == 0)
                last = i;
            else
                last = i - 1;
        }

        return (arr[0]);
    }
};

// { Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}
// } Driver Code Ends