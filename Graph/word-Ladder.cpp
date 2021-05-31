class Solution {
public:
    
    
    bool dif(string a, string b)
    {
        int d=0;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i] != b[i])
                d++;
            
            if(d>1)
                return false;
        }
        
        if(d == 1)
            return true;
        
        return false;
    }
    
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        
        int n = wordList.size();
        vector<bool> vis(n, false);
        int i, j, d;
        queue<pair<string, int>> q;
        string s;
        
        q.push({beginWord, 0});
        
        while(!q.empty())
        {
            s = (q.front()).first;
            d = (q.front()).second;
            q.pop();
            
            if(s == endWord)
                return d+1;
            
            for(i=0; i<n; i++)
            {
                if(!vis[i])
                {
                    if(dif(s, wordList[i]))
                    {
                        vis[i] = true;
                        q.push({wordList[i], d+1});
                    }
                }
            }
        }
        
        return 0;
    }
};
