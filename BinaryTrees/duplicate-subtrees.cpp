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

vector<int> ans;
string printAllDups(Node *root, map<string, int> &mm);

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    struct Node *child;
    scanf("%d\n", &t);
    while (t--)
    {
        map<int, Node *> m;
        int n;
        scanf("%d\n", &n);
        struct Node *root = NULL;
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
        map<string, int> mm;
        printAllDups(root, mm);
        cout << endl;
        if (ans.empty())
            cout << "-1";
        else
        {
            sort(ans.begin(), ans.end());
            for (auto x : ans)
                cout << x << " ";
        }
    }
    return 0;
} // } Driver Code Ends

//function Template for C++
/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line
string printAllDups(Node *root, map<string, int> &mm)
{
    if (root == NULL)
        return "";

    string str = "(";
    str += printAllDups(root->left, mm);
    str += to_string(root->data);
    str += printAllDups(root->right, mm);
    str += ")";

    if (mm[str] == 1)
    {
        ans.push_back(root->data);
    }

    mm[str]++;

    return str;
}
