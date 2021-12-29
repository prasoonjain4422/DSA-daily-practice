#include <bits/stdc++.h>
using namespace std;

//Q - cloning a linked list with random pointers ?

// Brute force approach will be making a new list just like build list function
// in O(n) time and O(n) space.


// More better approach will be adding duplicate pointers after every node and 
// separate the lists to form a cloned list. It will take O(n) time and O(1) space.


struct Node
{
    int data;
    Node *next = NULL;
    Node *random = NULL;
};

class Solution
{
public:
    Node *buildList(int n)
    {
        // O(n)

        if (n == 0)
            return NULL;

        int currData;
        Node *addr[n];

        cin >> currData;
        Node *root = new Node;
        addr[0] = root;
        root->data = currData;
        Node *temp = root;

        for (int i = 1; i < n; i++)
        {
            // O(n)

            cin >> currData;
            temp->next = new Node();
            temp = temp->next;
            addr[i] = temp;
            temp->data = currData;
        }

        temp = root;
        for (int i = 0; i < n; i++)
        {
            // O(n)

            cin >> currData;
            temp->random = addr[currData - 1];
            temp = temp->next;
        }

        return root;
    }

    void printList(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        printList(root->next);
    }

    void printRandomList(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->random->data << " ";
        printRandomList(root->next);
    }

    Node *clone(Node *root)
    {
        if (root == NULL)
            return root;

        if (root->next == NULL)
        {
            Node *cloned = new Node();
            cloned->data = root->data;

            if (root->random == NULL)
            {
                cloned->random = NULL;
            }
            else
            {
                cloned->random = cloned;
            }

            return cloned;
        }

        Node *rootTra = root;
        Node *temp;

        //      root
        //      1 -> 2 -> 3 -> 4 -> 5

        while (rootTra != NULL)
        {
            temp = rootTra->next;
            rootTra->next = new Node();

            rootTra->next->data = rootTra->data;
            rootTra->next->next = temp;

            rootTra = rootTra->next->next;
        }

        //      root
        //      1 -> 1n -> 2 -> 2n -> 3 -> 3n -> 4 -> 4n -> 5 -> 5n

        rootTra = root;
        while (rootTra != NULL)
        {
            rootTra->next->random = rootTra->random->next;
            rootTra = rootTra->next->next;
        }

        //      now we need to separate the lists

        rootTra = root;
        Node *cloned = root->next;
        Node *cloneTra = cloned;

        while (rootTra != NULL)
        {
            temp = rootTra->next;

            if (rootTra->next != NULL)
            {
                rootTra->next = rootTra->next->next;
            }

            rootTra = temp;
        }

        return cloned;
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, n, k;

    Solution obj;

    cin >> t;
    while (t--)
    {
        // number of Nodes
        cin >> n;

        Node *root = obj.buildList(n);

        obj.printList(root);
        cout << endl;
        obj.printRandomList(root);
        cout << endl;

        Node *cloned = obj.clone(root);
        cout << endl;

        obj.printList(cloned);
        cout << endl;
        obj.printRandomList(cloned);
        cout << endl;
    }

    return 0;
}
