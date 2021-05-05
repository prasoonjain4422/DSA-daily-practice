                continue;

                continue;

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int N)
    {
        
        sort(a, a+N);
        
        int ans=1, fans=1, i;
        
        for(i=0;i<N-1;i++)
        {
            if(a[i]==a[i+1])
                continue;
            
            
            if(a[i+1] == (a[i] + 1))
                ans++;
            else
            {
                fans = max(fans, ans);
                ans = 1;
            }
        }
        fans = max(fans, ans);
        
        return fans;
        
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends