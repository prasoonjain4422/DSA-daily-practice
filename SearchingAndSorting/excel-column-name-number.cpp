// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int N)
    {
        string ans = "";
        
        if(N < 27)
        {
            ans += (char)(64 + N);
            return ans;
        }
        else
        {
            
            int i=1, j, r;
            
            while(N>0)
            {
                r = N % 26;
                
                if(r == 0)
                {
                    ans += "Z";
                    N = N/26 - 1;
                }
                else
                {
                    ans += (char)(64 + r);
                    N = N/26;
                }
            }
            
            reverse(ans.begin(), ans.end());
            return ans;
        }
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
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
      // } Driver Code Ends