// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) 
{
    
    int n = A.length();
    int m = B.size();
    int i = 0, j, k;
    
    for(j=0; j<m; j++)
    {
        if(B[j][0] == A[i])
        {
            k = 0;
            while((k < B[j].size())&&(A[i+k] == B[j][k]))
            {
                k++;
            }
            
            if(k == B[j].size())
            {
                i += k;
                j = -1;
                
                if(i == A.size())
                {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}