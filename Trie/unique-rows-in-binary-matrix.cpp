// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


struct Trie 
{
    Trie* child[2];
    bool isEnd = false;
};

// void dfs(Trie* itr, vector<vector<int>> &ans, vector<int> cur)
// {
    
//     if(itr->isEnd)
//     {
//         ans.push_back(cur);
//     }
    
//     if(itr->child[0] != NULL)
//     {
//         cur.push_back(0);
//         dfs(itr->child[0], ans, cur);
//         cur.pop_back();
//     }
    
//     if(itr->child[1] != NULL)
//     {
//         cur.push_back(1);
//         dfs(itr->child[1], ans, cur);
//     }
// }

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    
    int i, j;
    Trie* root = new Trie();
    
    vector<vector<int>> ans;
    
    for(i=0; i<row; i++)
    {
        Trie* itr = root;
        vector<int> cur;
        for(j=0; j<col; j++)
        {
            cur.push_back(M[i][j]);
            if(itr->child[M[i][j]] == NULL)
            {
                itr->child[M[i][j]] = new Trie();
                itr = itr->child[M[i][j]];
            }
            else
            {
                itr = itr->child[M[i][j]];
            }
        }
        
        if(!itr->isEnd)
        {
            ans.push_back(cur);
            itr->isEnd = true;
        }
    }
    
    return ans;
}