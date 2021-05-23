// { Driver Code Starts
// C++ implementation to count pairs from two
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function

void make(Node *root, vector<int> &v)
{
    if(root == NULL)
        return;
    
    
    make(root->left, v);
    v.push_back(root->data);
    make(root->right, v);
    
}

int countPairs(Node* root1, Node* root2, int x)
{
    vector<int> a, b;
    make(root1, a);
    make(root2, b);
    
    int i=0, j=b.size()-1, ans=0;

    while((i<a.size())&&(j>=0))
    {
        if(a[i] + b[j] == x)
        {
            ans++;
            j--;
            i++;
        }
        else if((a[i] + b[j]) > x)
            j--;
        else
            i++;
    }
    
    return ans;
}