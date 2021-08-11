#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    
    // static int solve(vector<pair<pair<int, int>, int>> &a, int l, int b)
    // {
        
    //     int ans = 0;
    //     for(auto x: a)
    //     {
    //         if((x.first.first < l)&&(x.first.second < b))
    //             ans = max(ans, solve(a, x.first.first, x.first.second) + x.second);
    //     }
        
    //     return ans;
    // }
    
    int maxHeight(int height[],int width[],int length[],int n)
    {
        
        vector<pair<int, pair<pair<int, int>, int>>> a;
        
        int i, j, l = INT_MAX, b = INT_MAX, dp[3*n], ans;
        
        
        for(i=0; i<n; i++)
        {
            a.push_back({length[i]*width[i],   {{max(width[i], length[i]), min(width[i], length[i])}, height[i]}});
            a.push_back({length[i]*height[i], {{max(height[i], length[i]), min(height[i], length[i])}, width[i]}});
            a.push_back({height[i]*width[i],  {{max(height[i], width[i]), min(height[i], width[i])}, length[i]}});
        }
        
        sort(a.begin(), a.end());
        
        // return solve(a, INT_MAX, INT_MAX);
        
        ans = 0;
        for(i=0; i<3*n; i++)
        {
            dp[i] = 0;
                
            l = a[i].second.first.first;
            b = a[i].second.first.second;
                
                
            for(j=0; j<i; j++)
            {
                if((l > a[j].second.first.first)&&(b > a[j].second.first.second))
                {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            
            dp[i] += a[i].second.second;
            
            ans = max(ans, dp[i]);
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends