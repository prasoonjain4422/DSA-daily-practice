// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    static void dfs(vector<int> &A, int B, vector<vector<int>> &ans, vector<int> cur, int i)
    {
        if(B < 0)
            return;
            
        cur.push_back(A[i]);
        if(B == 0)
        {
            sort(cur.begin(), cur.end());
            ans.push_back(cur);
            return;
        }
        
        for(i; i<A.size(); i++)
        {
            if(A[i] != 0)
            {
                dfs(A, B-A[i], ans, cur, i);
            }
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) 
    {
        
        int i;
        vector<vector<int>> ans;
        vector<int> cur;
        unordered_map<int, bool> um;
        
        for(i=0; i<A.size(); i++)
        {
            if(um[A[i]])
            {
               A[i] = 0; 
            }
            else
            {
                um[A[i]] = true;
            }
        }
        
        for(i=0; i<A.size(); i++)
        {
            if(A[i] != 0)
            {
                dfs(A, B-A[i], ans, cur, i);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends