// { Driver Code Starts
//

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

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    int preInd = 0;
    Node *buildTree(int in[], int pre[], int l, int r)
    {
        if (l > r)
            return NULL;

        Node *head = NULL;
        head = new Node(pre[preInd++]);
        for (int i = l; i <= r; i++)
        {
            if (in[i] == pre[preInd - 1])
            {
                head->left = buildTree(in, pre, l, i - 1);
                head->right = buildTree(in, pre, i + 1, r);
                break;
            }
        }
        return head;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, 0, n - 1);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends