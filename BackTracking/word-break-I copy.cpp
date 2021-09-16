// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    
    static unordered_map<string, bool> um;
    void ahead(int i, string &s, vector<string> &ans, string ps)
    {
        if(i == s.size())
        {
            ans.push_back(ps);
            return;
        }
        
        int j = 1;
        for(j; j+i<=s.size(); j++)
        {
            if(um[s.substr(i, j)])
            {
                ahead(i+j, s, ans, s + " " + s.substr(i, j));
            }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        
        int i, siz = s.size();
        vector<string> ans;
        
        um.clear();
        for(i=0; i<n; i++)
            um[dict[i]] = true;
        
        for(i=1; i<siz; i++)
        {
            if(um[s.substr(0, i)])
            {
                ahead(i, s, ans, "");
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends