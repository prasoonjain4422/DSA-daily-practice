// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int n, string s)
    {
        const int M = 1003;
        int i, j, k, len;
        int dpt[n][n];
        int dpf[n][n];
        memset(dpt, 0, sizeof(dpt));
        memset(dpf, 0, sizeof(dpf));
        
        for(len=1; len<=n; len+=2)
        {
            for(i=0; (i+len)<=n; i+=2)
            {
                j = i+len-1;
                
                if(i == j)
                {
                    if(s[i] == 'T')
                    {
                        dpt[i][j] = 1;
                        dpf[i][j] = 0;
                    }
                    else
                    {
                        dpt[i][j] = 0;
                        dpf[i][j] = 1;
                    }
                }
                else if(abs(i-j) == 2)
                {
                    
                    if(s[i+1] == '&')
                    {
                        dpt[i][j] = (dpt[i][j] + dpt[i][i]*dpt[j][j])%M;
                        
                        dpf[i][j] = (dpf[i][j] + dpt[i][i]*dpf[j][j] 
                                                + dpf[i][i]*dpt[j][j]
                                                + dpf[i][i]*dpf[j][j])%M;
                    }
                    else if(s[i+1] == '|')
                    {
                        dpt[i][j] = (dpt[i][j] + dpt[i][i]*dpf[j][j] 
                                                + dpf[i][i]*dpt[j][j]
                                                + dpt[i][i]*dpt[j][j])%M;
                        
                        dpf[i][j] = (dpf[i][j] + dpf[i][i]*dpf[j][j])%M;
                    }
                    else
                    {
                        dpt[i][j] = (dpt[i][j] + dpt[i][i]*dpf[j][j] 
                                                + dpf[i][i]*dpt[j][j])%M;
                        
                        dpf[i][j] = (dpf[i][j] + dpt[i][i]*dpt[j][j] 
                                                + dpf[i][i]*dpf[j][j])%M;
                    }
                }
                else
                {
                    
                    for(k=i; k<j; k+=2)
                    {
                        if(s[k+1] == '&')
                        {
                            dpt[i][j] = (dpt[i][j] + dpt[i][k]*dpt[k+2][j])%M;
                            
                            dpf[i][j] = (dpf[i][j] + dpt[i][k]*dpf[k+2][j] 
                                                    + dpf[i][k]*dpt[k+2][j]
                                                    + dpf[i][k]*dpf[k+2][j])%M;
                        }
                        else if(s[k+1] == '|')
                        {
                            dpt[i][j] = (dpt[i][j] + dpt[i][k]*dpf[k+2][j] 
                                                    + dpf[i][k]*dpt[k+2][j]
                                                    + dpt[i][k]*dpt[k+2][j])%M;
                            
                            dpf[i][j] = (dpf[i][j] + dpf[i][k]*dpf[k+2][j])%M;
                        }
                        else
                        {
                            dpt[i][j] = (dpt[i][j] + dpt[i][k]*dpf[k+2][j] 
                                                    + dpf[i][k]*dpt[k+2][j])%M;
                            
                            dpf[i][j] = (dpf[i][j] + dpt[i][k]*dpt[k+2][j] 
                                                    + dpf[i][k]*dpf[k+2][j])%M;
                        }
                    }
                }
            }
        }
        
        return dpt[0][n-1]%M;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends