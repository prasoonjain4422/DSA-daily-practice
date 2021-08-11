



// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

struct node
{
    int v = -1;
};


class Solution{
  public:

    static bool cmp(pair<char, node> &a, pair<char, node> &b)
    {
        return (a.second.v < b.second.v);
    }

    int longestKSubstr(string s, int k)
    {
        
        int d = 0, len = 0, ans = 0, n = s.length();
        unordered_map<char, node> um;
        map<int, char> itoc;
        
        int i, j;
        
        
        for(i=0; i<n; i++)
        {
            
            if(um[s[i]].v == -1)
            {
                
                if(d >= k)
                {
                    ans = max(ans, len);
                    len = i - (*itoc.begin()).first;

                    um.erase((*itoc.begin()).second);
                    itoc.erase((*itoc.begin()).first);
                }
                else
                {
                    d++;
                    len++;
                }
                
                um[s[i]].v = i;
                itoc[i] = s[i];
            }
            else
            {
                len++;
                
                itoc.erase(um[s[i]].v);
                um[s[i]].v = i;
                itoc[i] = s[i];
            }
            
        }
        
        
        if(d != k)
            return -1;
        
        return max(ans, len);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends