// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int sumOfLongRootToLeafPath(Node *root);

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
        map<int, Node *> m;
        int n;
        scanf("%d", &n);
        struct Node *root = NULL;
        struct Node *child;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        cout << sumOfLongRootToLeafPath(root) << endl;
    }
    return 0;
} // } Driver Code Ends

//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/
// your task is to complete this function

pair<int, int> fun(Node *root)
{
    pair<int, int> p, q;

    if ((root->left == NULL) && (root->right == NULL))
    {
        return make_pair(1, root->data);
    }

    if (root->left != NULL)
    {
        p = fun(root->left);
    }

    if (root->right != NULL)
    {
        q = fun(root->right);
        if ((q.first) > (p.first))
        {
            p = q;
        }
        else if (((q.first) == (p.first)) && (q.second > p.second))
        {
            p = q;
        }
    }

    p.first += 1;
    p.second += root->data;
    return p;
}

int sumOfLongRootToLeafPath(Node *root)
{
    if (root == NULL)
        return 0;

    return (fun(root)).second;
}
