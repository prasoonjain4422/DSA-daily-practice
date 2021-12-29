#include <bits/stdc++.h>
using namespace std;

// O(nlogn) approach (building from root to leaves)
// find middle element and make it root 
// recursively find left and right subtrees;


// O(n) approach (building from leaves to root)
// find number of elements and recur for left and right 
// make new node when found leave node



struct BstNode
{
    int data;
    BstNode *left = NULL, *right = NULL;
};

struct LlNode
{
    int data;
    LlNode *next = NULL;
};

BstNode *solve(LlNode *root)
{

    if (root == NULL)
    {
        return NULL;
    }

    LlNode *t1 = root, *t2 = root, *prev;

    // for getting the middle node
    prev = NULL;
    while (t2 != NULL)
    {
        t2 = t2->next;
        if (t2 != NULL)
        {
            t2 = t2->next;
            prev = t1;
            t1 = t1->next;
        }
    }

    // t1  t2
    // 0   0
    // 1   1
    // 1   2
    // 2   3
    // 2   4
    // 3   5
    // 3   6
    // 4   7
    // 4   8 and so on...

    BstNode *ans = new BstNode();

    ans->data = t1->data;

    ans->right = solve(t1->next);

    if (prev != NULL)
    {
        prev->next = NULL;
        ans->left = solve(root);
    }

    return ans;
}

void inorder(BstNode *root)
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k;

    cin >> n;

    if (n == 0)
    {
        return 0;
    }

    struct LlNode *root, *temp;
    root = new LlNode();

    cin >> j;
    root->data = j;
    temp = root;

    for (i = 1; i < n; i++)
    {
        temp->next = new LlNode();
        temp = temp->next;
        cin >> temp->data;
    }

    BstNode *ans = solve(root);

    inorder(ans);

    cout << endl;
    return 0;
}
