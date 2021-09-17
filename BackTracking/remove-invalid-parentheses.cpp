#include<bits/stdc++.h>
using namespace std;

unordered_map<string, bool> vis;
class Solution {
public:
    
    static bool isv(string str)
    {
        int i, n = str.size();
        stack<char> s;

        
        for(i=0; i<n; i++)
        {
            if(str[i] == '(')
            {
                s.push('(');
            }
            else if(str[i] == ')')
            {
                if((!s.empty())&&(s.top() == '('))
                {
                    s.pop();
                }
                else
                {
                    s.push(')');
                }
            }
        }
        
        if(s.empty())
            return true;
        
        return false;
    }
    
    static void dfs(string str, int j, vector<string> &ans)
    {
        
        if(vis[str])
            return;
        
        if(j == 0)
        {
            if((isv(str))&&(!vis[str]))
            {
                vis[str] = true;
                ans.push_back(str);
            }
        }
        else
        {
            int i, n = str.size();
            
            for(i=0; i<n-1; i++)
            {
                dfs(str.substr(0, i) + str.substr(i+1), j-1, ans);
            }
            dfs(str.substr(0, n-1), j-1, ans);
        }
        
        
        vis[str] = true;
    }
    
    
    vector<string> removeInvalidParentheses(string str)
    {
        
        int i, j, n = str.size();
        vis.clear();
        stack<char> s;
        
        for(i=0; i<n; i++)
        {
            if(str[i] == '(')
            {
                s.push('(');
            }
            else if(str[i] == ')')
            {
                if((!s.empty())&&(s.top() == '('))
                {
                    s.pop();
                }
                else
                {
                    s.push(')');
                }
            }
        }
        
        vector<string> ans;
        j = s.size();
        
        if(j > 0)
        {
            for(i=0; i<n-1; i++)
            {
                dfs(str.substr(0, i) + str.substr(i+1), j-1, ans);
            }
            dfs(str.substr(0, n-1), j-1, ans);
        }
        
        
        if(ans.empty())
        {
            ans.push_back(str);
        }
            
        return ans;
    }
};
