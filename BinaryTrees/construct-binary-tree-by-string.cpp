#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left = NULL;
    Node *right = NULL;
    int data;
};

Node *node(int val)
{
    Node *temp = new Node;
    temp->data = val - 48;
    return temp;
}

Node *buildTree(string s, int *i)
{
    Node *temp = node((int)s[*i]);
    (*i)++;
    if ((*i + 1) < s.size())
    {
        if (s[*i] == '(')
        {
            if (s[*i + 1] != ')')
            {
                (*i)++;
                temp->left = buildTree(s, i);
                (*i)++;
            }
            if ((*i + 1) < s.size())
            {
                if (s[*i + 1] != ')')
                {
                    (*i)++;
                    temp->right = buildTree(s, i);
                    (*i)++;
                }
            }
        }
    }
    return temp;
}

void traver(Node *head)
{
    if (head == NULL)
        return;

    queue<Node *> q;
    q.push(head);
    head = NULL;

    while (!q.empty())
    {
        head = q.front();
        q.pop();
        cout << head->data << " ";

        if (head->left != NULL)
            q.push(head->left);

        if (head->right != NULL)
            q.push(head->right);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int i = 0;

    traver(buildTree(s, &i));

    return 0;
}
