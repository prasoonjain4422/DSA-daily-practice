// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    static bool isPalin(string &s, int i, int j)
    {
        
        while(i<j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
    
    static void dfs(string &s, vector<vector<string>> &ans, vector<string> &cur, int i)
    {
        if(i == s.size())
        {
            ans.push_back(cur);
            return;
        }
        
        
        for(int j=i; j<s.size(); j++)
        {
            if(isPalin(s, i, j))
            {
                cur.push_back(s.substr(i, j-i+1));
                dfs(s, ans, cur, j+1);
                cur.pop_back();
            }
        }
        
        return;
    }
    
    
    vector<vector<string>> allPalindromicPerms(string s)
    {
        
        int i, j, n = s.length();
        
        vector<vector<string>> ans;
        vector<string> cur;
        
        dfs(s, ans, cur, 0);
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends