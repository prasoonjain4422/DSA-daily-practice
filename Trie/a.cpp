#include <bits/stdc++.h>
using namespace std;

string ans;
class Solution
{
    public:
    
    static void dfs(string str, int k, int i)
    {
        
        if((k <= 0)||(i >= str.size()))
            return;
        

        int j, maxn;
        maxn = str[i]-48;
        for(j=i+1; j<str.size(); j++)
        {
            if((str[j]-48) > maxn)
            {
                maxn = str[j]-48;
            }
        }


        if(maxn != (str[i]-48))
        {
            
            for(int j = i+1; j<str.size(); j++)
            {
                if(maxn == (str[j]-48))
                {
                    swap(str[i], str[j]);
                    if(str > ans)
                    {
                        ans = str;
                    }
                    dfs(str, k-1, i+1);
                    swap(str[i], str[j]);
                }
            }
        }
        else
        {
            dfs(str, k, i+1);
        }
        
    }
    
    

    string findMaximumNum(string str, int k)
    {
        
        ans = str;
        dfs(str, k, 0);
        
        return ans;
        
    }
};


int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends