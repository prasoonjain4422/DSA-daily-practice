#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// time complexity :-
    


struct TrieNode 
{
    TrieNode* child[26];
    bool isEnd = false;
};


class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) 
    {
        
        vector<vector<string>> ans;
        
        TrieNode* root = new TrieNode();
        int i, j, n = string_list.size();
        
        for(i=0; i<n; i++)
        {
            string temp = string_list[i];
            TrieNode* itr = root;
            for(auto x: temp)
            {
                
                if(itr->child[x-'a'] == NULL)
                {
                    itr->child[x-'a'] = new TrieNode();
                    itr = itr->child[x-'a'];
                }
                else
                {
                    itr = itr->child[x-'a'];
                }
                
                itr->isEnd = true;
            }
        }
        
        vector<bool> vis(n, false);
        
        for(i=0; i<n; i++)
        {
            
            if(!vis[i])
            {
                vector<string> tempans;
                string temp = string_list[i];
                tempans.push_back(temp);
                
                sort(temp.begin(), temp.end());
                
                for(j=i+1; j<n; j++)
                {
                    if(!vis[j])
                    {
                        string temp2 = string_list[j];
                        sort(temp2.begin(), temp2.end());
                        
                        if(temp == temp2)
                        {
                            tempans.push_back(string_list[j]);
                            vis[j] = true;
                        }
                    }
                }
                vis[i] = true;
                ans.push_back(tempans);
            }
        }
        
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends