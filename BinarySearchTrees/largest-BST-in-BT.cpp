// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int largestBst(Node *root);

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
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
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        //getline(cin, s);
        // int k = stoi(s);
        // getline(cin, s);

        cout << largestBst(root1);
        cout << endl;
        //cout<<"~"<<endl;
    }
    return 0;
} // } Driver Code Ends

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST

int fun(Node *root, vector<int> &v)
{
    if ((root->left == NULL) && (root->right == NULL))
    {
        return 1;
    }

    int l = 0, r = 0;
    if (root->left != NULL)
    {
        l = fun(root->left, v);
        if (l != -1)
        {
            if (root->data <= root->left->data)
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    if (root->right != NULL)
    {
        r = fun(root->right, v);
        if (r != -1)
        {
            if (root->data >= root->right->data)
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    v.push_back(l + r + 1);
    return (l + r + 1);
}

int largestBst(Node *root)
{
    if (root == NULL)
        return 0;

    vector<int> v;
    v.push_back(1);
    v.push_back(fun(root, v));

    return *max_element(v.begin(), v.end());
}
