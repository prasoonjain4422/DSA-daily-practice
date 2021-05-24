// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    
    static bool cmp(vector<int> a, vector<int> b)
    {
        if(a[0] != b[0])
            return (a[0]<b[0]);
        else if(a[1] != b[1])
            return (a[1]<b[1]);
        else if(a[2] != b[2])
            return (a[2]<b[2]);
        else
            return (a[3]<b[3]);
        
    }
    
    
    vector<vector<int> > fourSum(vector<int> &a, int s) 
    {
        map<int, pair<int, pair<int, int> > > mm;
        map<int, bool> mmc;
        vector<int> ans(4);
        vector<vector<int>> ans2;
        
        
        int n = a.size();
        int i, j, k, l;
        int t;
        
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(mmc[a[k]])
                    {
                        ans[0] = a[(mm[a[k]]).first];
                        ans[1] = a[(mm[a[k]]).second.first];
                        ans[2] = a[(mm[a[k]]).second.second];
                        ans[3] = a[k];
                        
                        sort(ans.begin(), ans.end());
                        ans2.push_back(ans);
                        break;
                    }
                    
                    mmc[s - a[i] - a[j] - a[k]] = true;
                    mm[s - a[i] - a[j] - a[k]] = make_pair(i, make_pair(j, k));
                }
                mmc.clear();
                mm.clear();
            }
        }
        
        sort(ans2.begin(), ans2.end(), cmp);
        return ans2;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends